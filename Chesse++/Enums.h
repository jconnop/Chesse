#pragma once

namespace Chesse
{
	enum Color : unsigned int
	{
		White,
		Black,
		None
	};

	enum Piece : unsigned int
	{
		Rook,
		Knight,
		Bishop,
		Queen,
		King,
		Pawn
	};

	enum Side : unsigned int
	{
		Kingside,
		Queenside
	};


	enum Mask : uint64_t
	{
		ENPASSANT_ROWS = 280375481794560LL
	};

}
