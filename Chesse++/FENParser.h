#pragma once

#include "main.h"
#include "Board.h"
#include "Game.h"

namespace Chesse
{
	// Forward declarations
	class Board;
	class Game;

	class FENParser
	{

	public:
		FENParser(string FENString, Game &targetGame);
		void parse();

	private:
		string mFENString;
		Game &mGame; // Output game for parses data
		Board &mBoard; // Output board for parsed data

		void parseRank(int rank, string rankString);
		void parseCastles(string castleString);
		void parseEnPassant(string enPassantString);

		FENParser();
	};
}
