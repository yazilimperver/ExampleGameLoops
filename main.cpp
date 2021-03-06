#include <ConsoleUtil.h>
#include <LogoDisplayer.h>
#include <ConsoleSnakeGame.h>
#include <LoopManager.h>

#include <iostream>
#include <functional>
#include <thread>		
#include <conio.h>		   
#include <chrono>

using namespace std::chrono_literals;
using namespace std;	   

int main()
{
	// Perform console resizing
	setWindowSize(120, 40);

	/// Hide cursor
	cursorHide();
	
	/// Loop manager instance
	LoopManager loopMgr;

	/// Snake game
	ConsoleSnakeGame snakeGame{ loopMgr };

	/// Initial logo
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_LOGO);
												  
	/// Snake logo			
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_SPLASH);

	snakeGame.initialize();

	/// Sname game
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAME);

	snakeGame.display();

	loopMgr.registerDisplayFunction(std::bind(&ConsoleSnakeGame::displayWithLoopManagement, snakeGame, placeholders::_1));
	loopMgr.registerUpdateFunction(std::bind(&ConsoleSnakeGame::update, snakeGame, placeholders::_1));
	loopMgr.run();
}
