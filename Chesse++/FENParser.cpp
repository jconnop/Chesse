#include "FENParser.h"
#include <boost/lexical_cast.hpp>

namespace Chesse
{
	FENParser::FENParser(string FENString, Game &targetGame)
		: mGame(targetGame), mBoard(targetGame.getBoardRef())
	{
		this->mFENString = move(FENString);
	}


	void FENParser::parse()
	{
		vector<string> sections;
		boost::split(sections, mFENString, boost::is_any_of(" "));

		assert(sections.size() == 6);


		// First section: Piece placement
		vector<string> ranks;
		boost::split(ranks, sections.at(0), boost::is_any_of("/"));

		assert(ranks.size() == 8);

		int rank = 8;
		for (string rankString : ranks)
		{
			parseRank(rank, rankString);
			rank--;
		}

		// Second section: Active colour
		string color = sections.at(1);
		if (color == "w")
		{
			mGame.setActiveColor(Color::White);
		}
		else
		{
			mGame.setActiveColor(Color::Black);
		}

		// Third section: Castling availability
		parseCastles(sections.at(2));

		// Fourth section: En passant square
		parseEnPassant(sections.at(3));

		// Fifth section: Halfmove clock
		string halfMoveClockStr = sections.at(4);
		mGame.setHalfMoveClock(boost::lexical_cast<int>(halfMoveClockStr));

		// Sixth section: Fullmove number
		string fullMoveNumStr = sections.at(5);
		mGame.setFullMoveNumber(boost::lexical_cast<int>(fullMoveNumStr));

	}

	void FENParser::parseRank(int rank, string rankString)
	{
		int file = 1;

		for (char x : rankString)
		{
			switch (x)
			{
			case 'r':
				mBoard.setSquare(Color::Black, Piece::Rook, file, rank);
				break;
			case 'n':
				mBoard.setSquare(Color::Black, Piece::Knight, file, rank);
				break;
			case 'b':
				mBoard.setSquare(Color::Black, Piece::Bishop, file, rank);
				break;
			case 'q':
				mBoard.setSquare(Color::Black, Piece::Queen, file, rank);
				break;
			case 'k':
				mBoard.setSquare(Color::Black, Piece::King, file, rank);
				break;
			case 'p':
				mBoard.setSquare(Color::Black, Piece::Pawn, file, rank);
				break;
			case 'R':
				mBoard.setSquare(Color::White, Piece::Rook, file, rank);
				break;
			case 'N':
				mBoard.setSquare(Color::White, Piece::Knight, file, rank);
				break;
			case 'B':
				mBoard.setSquare(Color::White, Piece::Bishop, file, rank);
				break;
			case 'Q':
				mBoard.setSquare(Color::White, Piece::Queen, file, rank);
				break;
			case 'K':
				mBoard.setSquare(Color::White, Piece::King, file, rank);
				break;
			case 'P':
				mBoard.setSquare(Color::White, Piece::Pawn, file, rank);
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
				file += (x - '0' - 1); // Minus an extra 1 to offset loop increment below
				break;
			} // End switch

			file++;

		} // End for

		assert(file == 9); // After parsing a rank, file should have reached 9

	} // End parseFENRank

	void FENParser::parseCastles(string castleString)
	{
		for (char x : castleString)
		{
			switch (x)
			{
			case '-':
				return;
				break;
			case 'K':
				mBoard.setCastleAvailability(Color::White, Side::Kingside, true);
				break;
			case 'Q':
				mBoard.setCastleAvailability(Color::White, Side::Queenside, true);
				break;
			case 'k':
				mBoard.setCastleAvailability(Color::Black, Side::Kingside, true);
				break;
			case 'q':
				mBoard.setCastleAvailability(Color::Black, Side::Queenside, true);
				break;
			}
		}
	}

	void FENParser::parseEnPassant(string enPassantString)
	{
		if (enPassantString == "-")
		{
			return;
		}

		int file = (enPassantString.at(0) - 'a') + 1;
		int rank = (enPassantString.at(1) - '0');

		mBoard.setEnPassant(file, rank);
	}

} // End namespace
