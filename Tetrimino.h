#pragma once

#include <iostream>
#include <ctime>
#include <random>
#include <array>

const int TETRIMINO_SIZE=4;
typedef std::array<int, TETRIMINO_SIZE> TetriminoRow;
typedef std::array<TetriminoRow, TETRIMINO_SIZE> TetriminoGrid;

struct Location {
	int x; int y;
};


class Tetrimino {
public:
    enum class Type{J,I,L,O,S,T,Z,Random};
    enum class Color{ Blank, Red, Yellow, Teal, Blue, Orange, Green, Purple};
    Tetrimino(Type t=Type::Random);
	
	//Moving around
    Tetrimino& rotateLeft();
    Tetrimino& rotateRight();
    Tetrimino& moveLeft();
    Tetrimino& moveRight();
    Tetrimino& moveUp();
    Tetrimino& moveDown();
    
	//Accessors + Mutators
	Location getLocation() const;
	void setLocation(Location);
	void setLocation(int x, int y);
	Type getType() const;
	Color getColor() const;
	void setColor(Tetrimino::Color);
	TetriminoGrid getGrid() const;

	void dataDump(std::ostream&);
private:
	static bool seeded;	//Make sure generator is seeded once per run
    Type mType;
    Location mLocation;
    Color mColor;
    TetriminoGrid mGrid;
    void fillGrid(TetriminoGrid&, int);
    void initTetrimino(Type type, Color color);
};