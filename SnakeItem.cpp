#include <SnakeItem.h>	  
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ConsoleLevel.h>
#include <ConsoleUtil.h>

SnakeItem::SnakeItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo)
	: mSnakeHead{ level, initialCellInfo }
{
	level.getLevelBorders(mBorder);

	this->initialize(initialCellInfo);
}

void SnakeItem::initialize(const ConsoleCellData& initialCellInfo)
{
	mIsGameOver = false;

	mCurrentDirection = DIRECTION_RIGHT;
	mInitiatedDirection = DIRECTION_RIGHT;
	mAccumulatedTime = 0;
	mMoveTimeout = 500;
	mIgnoreInput = false;
	mAddBodyPart = false;
	mMovementLeftToAdd = 0;
	mNewBodyPartContent = 0;

	mSnakeBody.clear();
	mSnakeBodyContent.clear();

	// add additional body parts
	COORD body1 = initialCellInfo.mPosition;
	body1.X--;

	COORD body2 = body1;
	body2.X--;

	mSnakeBody.push_back(initialCellInfo.mPosition);
	mSnakeBodyContent.push_back('@');

	mSnakeBody.push_back(body1);
	mSnakeBodyContent.push_back('A');

	mSnakeBody.push_back(body2);
	mSnakeBodyContent.push_back('B');

	mCellToClear = body2;
}

void SnakeItem::displayItem()
{
	// First clear the last tail
	this->clearTail();

	for (size_t i = 0; i < mSnakeBody.size(); i++)
	{
		moveCursor(mSnakeBody[i]);
		std::cout << static_cast<char>(mSnakeBodyContent[i]);
	}
}

void SnakeItem::display()
{
}

void SnakeItem::update(float timePassedInMsec)
{
	if (false == mIsGameOver)
	{
		// Check keyboard input
		checkInput();			

		// Check for movement
		mAccumulatedTime += timePassedInMsec;

		if (mAccumulatedTime > mMoveTimeout)
		{
			mAccumulatedTime = 0;
			mIgnoreInput = false;

			this->performMove(mInitiatedDirection);
		}
	}
}

void SnakeItem::checkInput()
{
	// Check keyboard
	int readData = getNonBlockingChar();

	if (-1 != readData
		&&
		false == mIgnoreInput)
	{
		constexpr int KEY_UP = 0x48;
		constexpr int KEY_DOWN = 0x50;
		constexpr int KEY_LEFT = 0x4b;
		constexpr int KEY_RIGHT = 0x4d;

		switch (readData)
		{
		case KEY_LEFT:
			if (mCurrentDirection != DIRECTION_RIGHT)
			{
				mInitiatedDirection = DIRECTION_LEFT;
			}
			mIgnoreInput = true;
			break;
		case KEY_RIGHT:
			if (mCurrentDirection != DIRECTION_LEFT)
			{
				mInitiatedDirection = DIRECTION_RIGHT;
			}
			mIgnoreInput = true;
			break;
		case KEY_UP:
			if (mCurrentDirection != DIRECTION_DOWN)
			{
				mInitiatedDirection = DIRECTION_UP;
			}
			mIgnoreInput = true;
			break;
		case KEY_DOWN:
			if (mCurrentDirection != DIRECTION_UP)
			{
				mInitiatedDirection = DIRECTION_DOWN;
			}
			mIgnoreInput = true;
			break;
		case 'q':
		case 'Q':
			mAddBodyPart = true;
			mMovementLeftToAdd = mSnakeBodyContent.size();
			mNewBodyPartContent = 'A' + mSnakeBodyContent.size() - 1;
			mIgnoreInput = true;
			break;
		}
	}
}

void SnakeItem::performMove(eDirection direction)
{
	mInitiatedDirection = direction;
	mCurrentDirection = mInitiatedDirection;

	// Take head position of snake
	COORD newHead = mSnakeBody.front();

	// Move item according to direction
	switch (mCurrentDirection)
	{
	case SnakeItem::DIRECTION_LEFT:
		newHead.X--;
		break;
	case SnakeItem::DIRECTION_RIGHT:
		newHead.X++;
		break;
	case SnakeItem::DIRECTION_UP:
		newHead.Y--;
		break;
	case SnakeItem::DIRECTION_DOWN:
		newHead.Y++;
		break;
	}

	// Check game over case
	mIsGameOver = this->isGameOver(newHead);

	// Check boundary
	if ((false == mIsGameOver)
		&&
		(newHead.X < mBorder.right)
		&&
		(newHead.X >= mBorder.left)
		&&
		(newHead.Y >= mBorder.top)
		&&
		(newHead.Y < mBorder.bottom))
	{
		// add new head position to snake
		mSnakeBody.push_front(newHead);

		if (mMovementLeftToAdd > 0)
		{
			mMovementLeftToAdd--;
		}

		// remove tail position
		if (false == mAddBodyPart
			||
			mMovementLeftToAdd > 0)
		{
			// store new position to clear
			mCellToClear = mSnakeBody.back();

			mSnakeBody.pop_back();
		}
		else
		{
			mSnakeBodyContent.push_back(mNewBodyPartContent);

			mAddBodyPart = false;
		}

		// Display new snake
		this->displayItem();
	}
}

bool SnakeItem::isGameOver(const COORD& coordToCheck)
{
	if ((coordToCheck.X >= mBorder.right)
		||
		(coordToCheck.X < mBorder.left)
		||
		(coordToCheck.Y < mBorder.top)
		||
		(coordToCheck.Y >= mBorder.bottom))
		return true;
	else
		return false;
}

bool SnakeItem::isGameOver() const
{
	return mIsGameOver;
}

void SnakeItem::clearTail()
{
	moveCursor(mCellToClear.X, mCellToClear.Y);
	std::cout << ' ';
}

