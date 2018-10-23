#include <ConsoleSnakeGame.h>	 
#include <ConsoleUtil.h>		
#include <LoopManager.h>  
#include <iostream>				  
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

	/// First display level (order is important for initialization)
	/// TODO: add layer management
	level.display();

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

void ConsoleSnakeGame::displayWithLoopManagement(float tickTime)
{
	/// TODO: will be removed
	snake.display();

	// Display fps at top right	
	setColor(Color::eColor_black, Color::eColor_green);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 90, 0 });
	cout << "FPS : " << mLoopManager.getLastFPS();
}
