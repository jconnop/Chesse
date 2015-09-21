#pragma once

#include "main.h"

namespace Chesse
{

	class Player
	{

	public:
		Player(Color color);
		~Player();

		// Gets next move for player
		// TODO: some type of 'Move' return type
		//GetMove(Board *board);

	private:
		Player();

		Color mColor;

	};
}
