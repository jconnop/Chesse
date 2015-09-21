
#include "main.h"

#include "Game.h"

int main(int argc, char** argv)
{
	cout << "Hello, world!" << endl;

	Chesse::Player white(Chesse::Color::White);
	Chesse::Player black(Chesse::Color::Black);

	Chesse::Game game(white, black);

	Chesse::Color winner = game.Play();

	switch (winner)
	{
	case Chesse::Color::White:
		cout << "White wins!" << endl;
		break;
	case Chesse::Color::Black:
		cout << "Black wins!" << endl;
		break;
	case Chesse::Color::None:
		cout << "Everybody loses." << endl;
		break;
	}

	waitForClose();
	return 0;
}

void waitForClose()
{
	string temp;
	cin >> temp;
}
