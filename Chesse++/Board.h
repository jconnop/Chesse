#pragma once

#include "main.h"

namespace Chesse
{
	class Board
	{

	public:
		Board();

		bitboard getBlackPieces();
		bitboard getWhitePieces();
		bitboard getAllPieces();
		bitboard getPieces(Color color);

		void setSquare(Color color, Piece piece, int file, int rank);

		void setBitboardSquare(bitboard *bb, int file, int rank);
		bitboard getBitboardSquare(bitboard bb, int file, int rank);
		void clearBitboardSquare(bitboard *bb, int file, int rank);

		inline int getBitboardLocation(int file, int rank);

		void setCastleAvailability(Color color, Side side, bool available);

		void setEnPassant(int file, int rank);
		void clearEnPassant();

		string toString();

	private:
		bitboard mWhiteRooks = 0LL;
		bitboard mWhiteKnights = 0LL;
		bitboard mWhiteBishops = 0LL;
		bitboard mWhiteQueens = 0LL;
		bitboard mWhiteKing = 0LL;
		bitboard mWhitePawns = 0LL;

		bitboard mBlackRooks = 0LL;
		bitboard mBlackKnights = 0LL;
		bitboard mBlackBishops = 0LL;
		bitboard mBlackQueens = 0LL;
		bitboard mBlackKing = 0LL;
		bitboard mBlackPawns = 0LL;

		/* Stores available castling and en passant states
		   1 in rook position if that rook's castling is available
		   1 in a rank 3 or 6 position if en passant is available
		   These 2 state types have no position overlap so storing in one bitboard */
		bitboard mSpecialMoves = 0LL;
	};
}
