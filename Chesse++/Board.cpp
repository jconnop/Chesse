#include "Board.h"

namespace Chesse
{
	Board::Board()
	{
		std::string defaultFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
		parseFEN(defaultFEN);
	}

	Board::Board(std::string FENString)
	{
		parseFEN(FENString);
	}

	bitboard Board::getBlackPieces()
	{
		return mBlackRooks & mBlackKnights & mBlackBishops & mBlackQueens & mBlackKing & mBlackPawns;
	}

	bitboard Board::getWhitePieces()
	{
		return mWhiteRooks & mWhiteKnights & mWhiteBishops & mWhiteQueens & mWhiteKing & mWhitePawns;
	}

	bitboard Board::getAllPieces()
	{
		return getBlackPieces() & getWhitePieces();
	}

	bitboard Board::getPieces(Player::Color color)
	{
		if (color == Player::Color::Black)
		{
			return getBlackPieces();
		}
		else
		{
			return getWhitePieces();
		}
	}

	void Board::parseFEN(std::string FENString)
	{
		// TODO
		// Split by space
		// Split first part by /
		// Parse all ranks
		// Parse special sections

	}

}
