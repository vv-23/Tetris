#pragma once
#include <fstream>
#include "Tetrimino.h"

const int WELL_WIDTH = 8;
const int WELL_HEIGHT = 24;

typedef std::array<Tetrimino::Color, WELL_WIDTH> BoardRow;
typedef std::array<BoardRow, WELL_HEIGHT> Board;


class Well {
public:
	Well();
	Well(Tetrimino::Color);
	Board getBoard();
	void boardDump(std::ostream&);
	bool addTetrimino(const Tetrimino&);
	bool clearFullRows();
	//DEBUG
	void parseBoardFromFile(const std::string&);
	Well(const std::string&);
private:
	bool tetriminoFit(const Tetrimino&);
	void moveRowsDown(int newBottomRow);
	
	bool topReached();
	void fillBoard(Tetrimino::Color);
	int mHeight;
	int mWidth;
	Board mBoard;
};