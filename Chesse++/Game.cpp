#include "Game.h"

namespace Chesse
{
	Game::Game(Player white, Player black, Board board) :
		mWhite(white), mBlack(black), mBoard(board)
	{

	}

	Game::~Game()
	{
	}

	Player::Color Game::Play()
	{
		Player::Color winner = Player::None;

		// While Board.notEnded
		//		Get and apply white turn
		//		Get and apply black turn

		return winner;
	}
}
