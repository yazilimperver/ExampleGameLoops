#include <iostream>
#include <chrono>
#include <thread>
#include "LoopManager.h"

#include "ConsoleUtil.h"

using namespace std::chrono_literals;
using namespace std;

constexpr int TICKS_PER_SECOND = 60;
constexpr int PER_TICK_SKIP_TIME_IN_MS = 1000 / TICKS_PER_SECOND;
constexpr int MAX_FRAMESKIP = 5;

/// Default update functions
void update(float timeInMsec)
{
	//cout << "[" << updateInOneLoop << "] th Update() called! Tick time: " << timeInMsec << endl;
}

/// Default display functions
void display(float timeInMsec)
{
	//this_thread::sleep_for(10ms);
	//cout << "Diplay() function is called. Tick time is: " << timeInMsec << endl;
}

void LoopManager::run()
{
	//this->loopApproach1();
	//this->loopApproach2();
	//this->loopApproach3();
	//this->loopApproach4Approach1();
	//this->loopApproach4Approach2();
	this->loopApproach5();
}

void LoopManager::registerUpdateFunction(UpdateCallbackFunction updateFunc)
{
	mUpdateMethod = std::bind(updateFunc, std::placeholders::_1);
}

void LoopManager::registerDisplayFunction(DisplayCallbackFunction displayFunc)
{
	
	mDisplayMethod = std::bind(displayFunc, std::placeholders::_1);
}

int LoopManager::getLastFPS() const
{
	return lastFPS;
}

/// Return the time in milliseconds
inline long long GetTimeInMSec()
{
	auto duration = chrono::high_resolution_clock::now().time_since_epoch();
	return chrono::duration_cast<chrono::milliseconds>(duration).count();
}

void LoopManager::checkFunctionCallbacks()
{
	if (nullptr == mUpdateMethod)
	{
		mUpdateMethod = std::bind(update, std::placeholders::_1);

		if (true == enableConsolePrint)
			cout << "No update method is registered! Default update method will be utilized." << endl;
	}

	if (nullptr == mDisplayMethod)
	{
		mDisplayMethod = std::bind(display, std::placeholders::_1);

		if (true == enableConsolePrint)
			cout << "No display method is registered! Default display method will be utilized." << endl;
	}
}

void LoopManager::loopApproach1()
{ 
	this->checkFunctionCallbacks();

	auto previous(chrono::high_resolution_clock::now());
	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	while (mIsGameRunning)
	{							 
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();
		previous = current;

		// Update method
		mUpdateMethod(PER_TICK_SKIP_TIME_IN_MS);

		// Display method
		mDisplayMethod(elapsed);

		// Reporting stuff	
		this->reportStatistics(elapsed);
	}
}

void LoopManager::loopApproach2()
{
	this->checkFunctionCallbacks();

	auto nextTickTime = GetTimeInMSec();

	long long sleepTime = 0;

	auto previous(chrono::high_resolution_clock::now());

	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	while (mIsGameRunning)
	{												   
		mUpdateMethod(PER_TICK_SKIP_TIME_IN_MS);
		updateCount++;

		mDisplayMethod(PER_TICK_SKIP_TIME_IN_MS);

		nextTickTime += PER_TICK_SKIP_TIME_IN_MS;

		// Calculate sleep time if so
		sleepTime = nextTickTime - GetTimeInMSec();

		if (sleepTime > 0)
		{
			this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		}

		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();

		previous = current;

		this->reportStatistics(elapsed);
	}
}

void LoopManager::loopApproach3()
{
	this->checkFunctionCallbacks();

	auto previous(chrono::high_resolution_clock::now());
	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	while (mIsGameRunning)
	{
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();
		previous = current;

		mUpdateMethod(elapsed);
		updateCount++;
		mDisplayMethod(elapsed);

		this->reportStatistics(elapsed);
	}
}

void LoopManager::loopApproach4Approach1()
{
	this->checkFunctionCallbacks();

	int loops;
	float interpolation = 0.0F;
	auto nextTickTime = GetTimeInMSec();
	auto previous(chrono::high_resolution_clock::now());

	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	// Game loop
	while (mIsGameRunning)
	{
		loops = 0;

		while (GetTimeInMSec() > nextTickTime
			&&
			loops < MAX_FRAMESKIP)
		{
			mUpdateMethod(PER_TICK_SKIP_TIME_IN_MS);

			updateCount++;
			nextTickTime += PER_TICK_SKIP_TIME_IN_MS;
			loops++;
		}

		mDisplayMethod(interpolation);

		// Loop calculations
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();
		previous = current;

		// Reporting stuff
		this->reportStatistics(elapsed);

	}
}

void LoopManager::loopApproach4Approach2()
{
	this->checkFunctionCallbacks();

	int loops; 
	float lag = 0;
	float displayInterpolation = 0.0F;

	auto previous(chrono::high_resolution_clock::now());

	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	// Game loop
	while (mIsGameRunning)
	{
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();

		// Loop calculations
		previous = current;
		lag += elapsed;
		loops = 0;

		while (lag > PER_TICK_SKIP_TIME_IN_MS
			&&
			loops < MAX_FRAMESKIP)
		{
			mUpdateMethod(PER_TICK_SKIP_TIME_IN_MS);

			lag -= PER_TICK_SKIP_TIME_IN_MS;
			loops++;
		}
		
		mDisplayMethod(elapsed);

		// Reporting stuff				
		this->reportStatistics(elapsed);
	}
}


/* The game state itself doesn’t need to be updated 60 times per second.
Player input, AI and the updating of the game state have enough with 25 frames per second.
So let’s try to call the update_game() 25 times per second, no more, no less.
The rendering, on the other hand, needs to be as fast as the hardware can handle.
But a slow frame rate shouldn’t interfere with the updating of the game.
The way to achieve this is by using the following game loop :*/
void LoopManager::loopApproach5()
{
	this->checkFunctionCallbacks();

	int loops;
	float interpolation = 0.0F;
	auto nextTickTime = GetTimeInMSec();				   
	auto previous(chrono::high_resolution_clock::now());	 

	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed;

	// Game loop
	while (mIsGameRunning)
	{	
		loops = 0;

		while (GetTimeInMSec() > nextTickTime
			&&
			loops < MAX_FRAMESKIP)
		{
			mUpdateMethod(PER_TICK_SKIP_TIME_IN_MS);

			updateCount++;
			nextTickTime += PER_TICK_SKIP_TIME_IN_MS;
			loops++;
		}

		interpolation = (GetTimeInMSec() + PER_TICK_SKIP_TIME_IN_MS - nextTickTime) / float(PER_TICK_SKIP_TIME_IN_MS);
		  
		mDisplayMethod(interpolation);

		// Loop calculations
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();
		previous = current;

		// Reporting stuff
		this->reportStatistics(elapsed);

	}
}

void LoopManager::reportStatistics(float elapsedTime)
{
	accumulatedTime += elapsedTime;
	tickCount++;
	displayCount++;

	if (accumulatedTime > reportTime)
	{
		lastFPS = static_cast<int>(tickCount * 1000 / accumulatedTime);
		if (true == enableConsolePrint)
		{
			clearConsole();
			cout << "The FPS is : " << lastFPS << endl
				<< "Tick count:" << tickCount << endl
				<< "Accumulated time:" << accumulatedTime << endl
				<< "Display count:" << displayCount << endl
				<< "Update count:" << updateCount << endl;
		}

		accumulatedTime = 0;
		displayCount = 0;
		updateCount = 0;
		tickCount = 0;
	}
}

