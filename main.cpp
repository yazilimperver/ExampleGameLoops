#include <ConsoleUtil.h>
#include <LogoDisplayer.h>
#include <ConsoleSnakeGame.h>
#include <LoopManager.h>

#include <iostream>
#include <functional>
#include <thread>		  
using namespace std::chrono_literals;
using namespace std;	   

int main()
{
	/// Hide cursor
	cursorHide();

	/// Display logo
	LogoDisplayer::DisplayYazilimPerverLogoText2();
	
	/// Wait a little bit
	this_thread::sleep_for(1s);

	/// Loop manager instance
	LoopManager loopMgr;

	/// Snake game
	ConsoleSnakeGame snakeGame{ loopMgr };
	snakeGame.initialize();
	snakeGame.display();

	loopMgr.registerDisplayFunction(std::bind(&ConsoleSnakeGame::displayWithLoopManagement, snakeGame, placeholders::_1));
	loopMgr.registerUpdateFunction(std::bind(&ConsoleSnakeGame::update, snakeGame, placeholders::_1));
	loopMgr.run();
}
