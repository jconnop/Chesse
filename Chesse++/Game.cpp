#include "Game.h"

namespace Chesse
{
	Game::Game(Player white, Player black) :
		mWhite(white), mBlack(black)
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