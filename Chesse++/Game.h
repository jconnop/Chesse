#pragma once
#include "main.h"

#include "Player.h"
#include "Board.h"

namespace Chesse
{
	class Game
	{

	public:
		Game(Player white, Player black, Board board);
		~Game();

		// Performs main game logic loop
		// Gets move for each player, checks if game ended, returns winner
		Player::Color Play();

	private:
		// Board state
		Board mBoard;

		// Players
		Player mWhite;
		Player mBlack;

		Player::Color mNextPlayer = Player::Color::White;

	};
}
