#include "Well.h"

Well::Well()
{
	fillBoard(Tetrimino::Color::Blank);
}

Well::Well(Tetrimino::Color c) {
	fillBoard(c);
}

bool Well::tetriminoFit(const Tetrimino & t)
{
	TetriminoGrid g = t.getGrid();
	for (int i = 0; i < TETRIMINO_SIZE; i++) {
		for (int j = 0; j < TETRIMINO_SIZE; j++) {
			int yPosOnBoard = i + t.getLocation().y;
			int xPosOnBoard = j + t.getLocation().x;
			int boardValueAtXY;
			if ((xPosOnBoard >= 0) && (xPosOnBoard < WELL_WIDTH) && (yPosOnBoard < WELL_HEIGHT)) {
				if ((yPosOnBoard >= 0)) {
					boardValueAtXY = static_cast<int>(mBoard[yPosOnBoard][xPosOnBoard]);
				}
				else if (yPosOnBoard >= -TETRIMINO_SIZE+1)
					boardValueAtXY = 0;
				else
					boardValueAtXY = 1;
			}
			else
				boardValueAtXY = 1;
			if (static_cast<int>(g[i][j]) && boardValueAtXY)
				return false;
		}
	}
	return true;
}

bool Well::addTetrimino(const Tetrimino &t)
{
	TetriminoGrid g = t.getGrid();
	if (tetriminoFit(t)) {
		for (int i = 0; i < TETRIMINO_SIZE; i++) {
			for (int j = 0; j < TETRIMINO_SIZE; j++) {
				if (g[i][j]) {
					int xPosOnBoard = j + t.getLocation().x;
					int yPosOnBoard = i + t.getLocation().y;
					if ((xPosOnBoard >= 0) && (xPosOnBoard < WELL_WIDTH) && (yPosOnBoard < WELL_HEIGHT) && (yPosOnBoard >= 0))
					mBoard[yPosOnBoard][xPosOnBoard] = t.getColor();
				}
			}
		}
		return true;
	}
	return false;
}

bool Well::clearFullRows()
{
	bool full = true;
	int fullRows = 0;
	int baseIndex = WELL_HEIGHT-1;
	for (int row = mBoard.size()-1; row >= 0; row--) {
		int i = 0;
		
		for (i = 0; i < mBoard[row].size(); i++) {
			if (mBoard[row][i] == Tetrimino::Color::Blank)
				break;
		}
		if (i==mBoard[row].size()) {
			fullRows++;
			//mBoard[row].fill(Tetrimino::Color::Blank);
		}
		else {
			mBoard[baseIndex] = mBoard[row];
			baseIndex--;
		}
	}
	return false;
}

void Well::parseBoardFromFile(const std::string &filename)
{
	std::ifstream f;
	f.open(filename);
	if (f.is_open()) {
		for (auto& row : mBoard) {
			for (auto& element : row) {
				int i;
				f >> i;
				element = static_cast<Tetrimino::Color>(i);
			}
		}
	}
	else fillBoard(Tetrimino::Color::Blank);
	f.close();
}

Well::Well(const std::string &filename)
{
	parseBoardFromFile(filename);
}

bool Well::topReached()
{
	return false;
}

void Well::fillBoard(Tetrimino::Color c)
{
	/*for (BoardRow i : mBoard) {
		for (Tetrimino::Color element : i) {
			element = c;
		}
	}*/
	for (int i = 0; i < WELL_HEIGHT; i++) {
		for (int j = 0; j < WELL_WIDTH; j++) {
			mBoard[i][j] = c;
		}
	}
}

Board Well::getBoard()
{
	return mBoard;
}

void Well::boardDump(std::ostream& stream)
{
	stream << "Board:\n";
	for (BoardRow i : mBoard) {
		for (Tetrimino::Color element : i) {
			stream << static_cast<int>(element) << " ";
		}
		stream << "\n";
	}
	stream << "########\n";
}
