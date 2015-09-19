#pragma once
#include "main.h"

namespace Chesse
{

	class Player
	{

	public:
		enum Color : unsigned int
		{
			White = 0,
			Black = 1,
			None = 2
		};

		Player(Player::Color color);
		~Player();

		// Gets next move for player
		// TODO: some type of 'Move' return type
		//GetMove(Board *board);

	private:
		Player();

		Player::Color mColor;

	};
}
