#include <ConsoleSnakeGame.h>	 
#include <ConsoleUtil.h>		
#include <LoopManager.h>  
#include <iostream>				  
#include <thread>

#include <LogoDisplayer.h>
#include <conio.h>		   
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

ConsoleSnakeGame::ConsoleSnakeGame(const LoopManager& loopManager) 
	: snake{ level, ConsoleCellData{ {4, 10}, '@', Color::eColor_blue, Color::eColor_black} }
, mLoopManager(loopManager)
{

}

void ConsoleSnakeGame::initialize()
{
	// load level
	level.load();
}

void ConsoleSnakeGame::update(float tickTime)
{
	if ( SnakeGameScreen::eGAME_SCREEN_GAME == mCurrentGameScreen)
	{
		if (false == snake.isGameOver())
		{
			snake.update(tickTime);
		}
		else
		{
			this->switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAMEOVER);
		}
	}
	else if (SnakeGameScreen::eGAME_SCREEN_GAMEOVER == mCurrentGameScreen)
	{
		this->displayGameOver();
	}
}

bool ConsoleSnakeGame::switchToGameScreen(SnakeGameScreen newScreen)
{
	bool isSwitchSuccess = false;

	switch (newScreen)
	{
	case SnakeGameScreen::eGAME_SCREEN_LOGO:
		if (SnakeGameScreen::eGAME_SCREEN_INITIAL == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_LOGO;
			this->displayLogo();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_SPLASH:
		if (SnakeGameScreen::eGAME_SCREEN_LOGO == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_SPLASH;
			this->displayGameLogo();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_MENU:
		if (SnakeGameScreen::eGAME_SCREEN_SPLASH == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_MENU;

			/// TODO
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_GAME:
		if (SnakeGameScreen::eGAME_SCREEN_MENU == mCurrentGameScreen
			||
			SnakeGameScreen::eGAME_SCREEN_SPLASH == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAME;
			this->prepareGameScreen();
			isSwitchSuccess = true;
		}
		else if (SnakeGameScreen::eGAME_SCREEN_GAMEOVER == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAME;
			clearConsole();
			this->prepareGameScreen();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_GAMEOVER:
		if (SnakeGameScreen::eGAME_SCREEN_GAME == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAMEOVER;
			this->displayGameOver();
			isSwitchSuccess = true;
		}
		break;
	default:
		break;
	}

	if (false == isSwitchSuccess)
	{
		setColor(Color::eColor_red, Color::eColor_yellow);
		displayCenteredText("Unexpected game screen change request!", 126, 38);
	}

	return isSwitchSuccess;
}

void ConsoleSnakeGame::displayGameOver()
{
	/// Set color
	setColor(Color::eColor_yellow, Color::eColor_red);
	
	auto previous(chrono::high_resolution_clock::now());
	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed = 0.0F;

	bool displayText = true;
	do
	{
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();

		if (elapsed > 1000)
		{
			displayText = !displayText;
			previous = current;
		}

		if (true == displayText)
		{
			displayCenteredText("GAME OVER!", 126, 15);
			displayCenteredText("Please Press Space Bar to restart menu!", 126, 36);
			displayCenteredText("Please Press Enter to continue watch game!", 126, 37);
		}
		else
		{
			displayCenteredText("          ", 126, 15);
		}
	} while (getNonBlockingChar() != ' ');

	// restart game
	this->switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAME);
}

void ConsoleSnakeGame::prepareGameScreen()
{
	/// First display level (order is important for initialization)
	/// TODO: add layer management
	level.display();

	/// Provide snake initial position
	snake.initialize(ConsoleCellData{ {4, 10}, '@', Color::eColor_blue, Color::eColor_black });

	/// Print player
	snake.displayItem();

	/// Display Title
	setColor(Color::eColor_red, Color::eColor_yellow);
	displayCenteredText("Empty ASCII Game Field Test. uEngin (c) 2018", 120, 0);
}

void ConsoleSnakeGame::display()
{
	snake.display();
}

void ConsoleSnakeGame::displayLogo()
{
	/// Set color
	setColor(Color::eColor_black, Color::eColor_white);

	/// Display logo
	LogoDisplayer::DisplayYazilimPerverLogoText1();

	/// Wait a little bit
	this_thread::sleep_for(2s);

	/// Clear console
	clearConsole();
}

void ConsoleSnakeGame::displayGameLogo()
{
	/// Set color
	setColor(Color::eColor_black, Color::eColor_green);

	LogoDisplayer::DisplaySnakeLogo();
	this_thread::sleep_for(2s);

	setColor(Color::eColor_black, Color::eColor_yellow);

	auto previous(chrono::high_resolution_clock::now());
	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed = 0.0F;

	bool displayText = true;
	do
	{
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();

		if (elapsed > 1000)
		{
			displayText = !displayText;
			previous = current;
		}

		if (true == displayText)
		{
			displayCenteredText("Please Press Space Bar to Continue!", 126, 37);
		}
		else
		{
			displayCenteredText("                                        ", 126, 37);
		}
	} while (getNonBlockingChar() != ' ');

	/// Clear console
	clearConsole();
}

void ConsoleSnakeGame::displayWithLoopManagement(float tickTime)
{
	/// TODO: will be removed
	snake.display();

	// Display fps at top right	
	setColor(Color::eColor_black, Color::eColor_green);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 90, 0 });
	cout << "FPS : " << mLoopManager.getLastFPS() << "    ";
}
