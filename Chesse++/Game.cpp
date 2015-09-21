#include "Game.h"

namespace Chesse
{
	Game::Game(Player white, Player black) :
		mWhite(white), mBlack(black)
	{
		mBoard = *new Board();

		string defaultFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
		FENParser fp(defaultFEN, *this);
		fp.parse();

		cout << mBoard.toString() << endl;
	}

	Game::Game(Player white, Player black, string FENString) :
		mWhite(white), mBlack(black)
	{
		mBoard = *new Board();

		FENParser fp(FENString, *this);
		fp.parse();
	}

	Game::~Game()
	{
		delete &mBoard;
	}

	Color Game::Play()
	{
		Color winner = Color::None;

		// While Board.notEnded
		//		Get and apply white turn
		//		Get and apply black turn

		return winner;
	}

	void Game::setActiveColor(Color color)
	{
		mActiveColor = color;
	}

	Color Game::getActiveColor()
	{
		return mActiveColor;
	}

	void Game::setHalfMoveClock(int halfMoveClock)
	{
		mHalfMoveClock = halfMoveClock;
	}

	int Game::getHalfMoveClock()
	{
		return mHalfMoveClock;
	}

	void Game::setFullMoveNumber(int fullMoveNumber)
	{
		mFullMoveNumber = fullMoveNumber;
	}

	int Game::getFullMoveNumber()
	{
		return mFullMoveNumber;
	}

	Board & Game::getBoardRef()
	{
		return mBoard;
	}
}
