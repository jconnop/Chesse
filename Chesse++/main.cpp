
#include "main.h"

#include "Game.h"

int main(int argc, char** argv)
{
	std::cout << "Hello, world!" << std::endl;

	Chesse::Player white(Chesse::Player::Color::White);
	Chesse::Player black(Chesse::Player::Color::Black);

	Chesse::Board board;

	Chesse::Game game(white, black, board);

	Chesse::Player::Color winner = game.Play();

	switch (winner)
	{
	case Chesse::Player::White:
		std::cout << "White wins!" << std::endl;
		break;
	case Chesse::Player::Black:
		std::cout << "Black wins!" << std::endl;
		break;
	case Chesse::Player::None:
		std::cout << "Everybody loses." << std::endl;
		break;
	}

	waitForClose();
	return 0;
}

void waitForClose()
{
	std::string temp;
	std::cin >> temp;
}
