#include "Board.h"

namespace Chesse
{
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

}
