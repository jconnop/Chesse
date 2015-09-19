#pragma once
#include "main.h"
#include "Player.h"

namespace Chesse
{
	class Board
	{

	public:
		bitboard getBlackPieces();
		bitboard getWhitePieces();
		bitboard getAllPieces();
		bitboard getPieces(Player::Color color);

	private:
		bitboard mWhiteRooks;
		bitboard mWhiteKnights;
		bitboard mWhiteBishops;
		bitboard mWhiteQueens;
		bitboard mWhiteKing;
		bitboard mWhitePawns;

		bitboard mBlackRooks;
		bitboard mBlackKnights;
		bitboard mBlackBishops;
		bitboard mBlackQueens;
		bitboard mBlackKing;
		bitboard mBlackPawns;

		/* Stores available castling and en passant states
		   1 in rook position if that rook's castling is available
		   1 in a rank 3 or 6 position if en passant is available
		   These 2 state types have no position overlap so storing in one bitboard */
		bitboard mSpecialMoves;

	};
}
