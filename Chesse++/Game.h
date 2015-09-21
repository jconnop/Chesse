#pragma once

#include "main.h"
#include "Board.h"
#include "Player.h"
#include "FENParser.h"

namespace Chesse
{
	// Forward Declarations
	class Board;

	class Game
	{

	public:
		// Initialises a Game with the given players and the default starting position
		Game(Player white, Player black);

		// Initialises a Game with the given players and starting state defined by FENString
		Game(Player white, Player black, string FENString);

		~Game();

		// Performs main game logic loop
		// Gets move for each player, checks if game ended, returns winner
		Color Play();

		void setActiveColor(Color color);
		Color getActiveColor();

		void setHalfMoveClock(int halfMoveClock);
		int getHalfMoveClock();

		void setFullMoveNumber(int fullMoveNumber);
		int getFullMoveNumber();


		Board& getBoardRef();

	private:
		// Board state
		Board mBoard;

		// Players
		Player mWhite;
		Player mBlack;

		Color mActiveColor = Color::None;

		int mHalfMoveClock = 0;

		int mFullMoveNumber = 1;

	};
}
