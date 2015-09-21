#include "Board.h"
#include <sstream>

namespace Chesse
{
	Board::Board()
	{
	}

	bitboard Board::getBlackPieces()
	{
		return mBlackRooks | mBlackKnights | mBlackBishops | mBlackQueens | mBlackKing | mBlackPawns;
	}

	bitboard Board::getWhitePieces()
	{
		return mWhiteRooks | mWhiteKnights | mWhiteBishops | mWhiteQueens | mWhiteKing | mWhitePawns;
	}

	bitboard Board::getAllPieces()
	{
		return getBlackPieces() | getWhitePieces();
	}

	bitboard Board::getPieces(Color color)
	{
		if (color == Color::Black)
		{
			return getBlackPieces();
		}
		else
		{
			return getWhitePieces();
		}
	}

	void Board::setSquare(Color color, Piece piece, int file, int rank)
	{
		switch(color)
		{
		case Color::White:
			switch (piece)
			{
			case Piece::Rook:
				setBitboardSquare(&mWhiteRooks, file, rank);
				break;
			case Piece::Knight:
				setBitboardSquare(&mWhiteKnights, file, rank);
				break;
			case Piece::Bishop:
				setBitboardSquare(&mWhiteBishops, file, rank);
				break;
			case Piece::Queen:
				setBitboardSquare(&mWhiteQueens, file, rank);
				break;
			case Piece::King:
				setBitboardSquare(&mWhiteKing, file, rank);
				break;
			case Piece::Pawn:
				setBitboardSquare(&mWhitePawns, file, rank);
				break;
			}
			break;
		case Color::Black:
			switch (piece)
			{
			case Piece::Rook:
				setBitboardSquare(&mBlackRooks, file, rank);
				break;
			case Piece::Knight:
				setBitboardSquare(&mBlackKnights, file, rank);
				break;
			case Piece::Bishop:
				setBitboardSquare(&mBlackBishops, file, rank);
				break;
			case Piece::Queen:
				setBitboardSquare(&mBlackQueens, file, rank);
				break;
			case Piece::King:
				setBitboardSquare(&mBlackKing, file, rank);
				break;
			case Piece::Pawn:
				setBitboardSquare(&mBlackPawns, file, rank);
				break;
			}
			break;
		}
	}

	void Board::setBitboardSquare(bitboard *bb, int file, int rank)
	{
		int shift = getBitboardLocation(file, rank);
		*bb ^= 1LL << shift;
	}

	bitboard Board::getBitboardSquare(bitboard bb, int file, int rank)
	{
		int shift = getBitboardLocation(file, rank);
		return bb & (1LL << shift);
	}

	void Board::clearBitboardSquare(bitboard *bb, int file, int rank)
	{
		int shift = getBitboardLocation(file, rank);
		*bb &= ~(1LL << shift);
	}

	inline int Board::getBitboardLocation(int file, int rank)
	{
		return (((rank - 1) * 8) + file - 1);
	}

	void Board::setCastleAvailability(Color color, Side side, bool available)
	{
		int file = (side == Side::Queenside) ? 1 : 8;
		int rank = (color == Color::White) ? 1 : 8;		

		if (available)
		{
			setBitboardSquare(&mSpecialMoves, file, rank);
		}
		else
		{
			clearBitboardSquare(&mSpecialMoves, file, rank);
		}
	}

	void Board::setEnPassant(int file, int rank)
	{
		setBitboardSquare(&mSpecialMoves, file, rank);
	}

	void Board::clearEnPassant()
	{
		mSpecialMoves &= ~Mask::ENPASSANT_ROWS;
	}

	string Board::toString()
	{
		bitboard allPieces = getAllPieces();

		ostringstream boardString;

		for (int i = 8; i >= 1; i--)
		{
			for (int j = 1; j <= 8; j++)
			{
				bitboard locationValue = getBitboardSquare(allPieces, j, i);
				boardString << (locationValue ? "1" : "0");
			}
			boardString << endl;
		}

		return boardString.str();
	}

}
