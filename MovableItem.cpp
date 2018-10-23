#include "MovableItem.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ConsoleLevel.h"
#include "ConsoleUtil.h"

MovableItem::MovableItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo)
	: mCellItem{ level, initialCellInfo }
{								 	
	level.getLevelBorders(mBorder);
}

void MovableItem::displayItem()
{
	mCellItem.display();
}

void MovableItem::display()
{			  							   
	// Check keyboard
	int readData = getNonBlockingChar();

	if (-1 != readData)
	{
		bool updatePreviousCell = false;

		COORD movement{ 0, 0 };

		constexpr int KEY_UP = 0x48;
		constexpr int KEY_DOWN = 0x50;
		constexpr int KEY_LEFT = 0x4b;
		constexpr int KEY_RIGHT = 0x4d;

		switch (readData)
		{
		case KEY_LEFT:
			updatePreviousCell = true;
			movement.X = -1;
			break;
		case KEY_RIGHT:
			updatePreviousCell = true;
			movement.X = 1;
			break;
		case KEY_UP:
			updatePreviousCell = true;
			movement.Y = -1;
			break;
		case KEY_DOWN:
			updatePreviousCell = true;
			movement.Y = 1;
			break;
		}

		if (true ==	updatePreviousCell)
		{
			const COORD coord = mCellItem.getCellItemData().mPosition;

			// Check boundary
			if (((coord.X + movement.X) < mBorder.right)
				&&
				((coord.X + movement.X) >= mBorder.left)
				&&
				((coord.Y + movement.Y) >= mBorder.top)
				&&
				((coord.Y + movement.Y) < mBorder.bottom))
			{
				movement.X += coord.X;
				movement.Y += coord.Y;
				
				mCellItem.moveTo(movement);
			}
		}
	}
}