#include "Tetrimino.h"

bool Tetrimino::seeded = false;

Tetrimino::Tetrimino(Tetrimino::Type type) {
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
    Type t=type;
    if (type==Type::Random) {    
        t = static_cast<Type>(rand()%7);
    }
    Color c = static_cast<Color>(rand()%6+1);
    initTetrimino(t,c);
	mLocation = Location{ 0,0 };
}

void Tetrimino::fillGrid(TetriminoGrid& g, int value) {
	for (auto i = g.begin(); i != g.end(); i++) {
		(*i).fill(value);
	}
}

void Tetrimino::initTetrimino(Type t, Color c) {
    //fillGrid(mGrid, 0);
	if (t == Type::J) {
		mGrid = TetriminoGrid{ TetriminoRow{{0,0,0,0}}, TetriminoRow{{0,1,0,0}}, TetriminoRow{{0,1,1,1}}, TetriminoRow{{0,0,0,0}} };
	}
	else if (t == Type::I) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 1,1,1,1 } }, TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	else if (t == Type::L) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 0,0,0,1 } }, TetriminoRow{ { 0,1,1,1 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	else if (t == Type::O) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 0,1,1,0 } }, TetriminoRow{ { 0,1,1,0 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	else if (t == Type::S) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 0,0,1,1 } }, TetriminoRow{ { 0,1,1,0 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	else if (t == Type::T) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 0,0,1,0 } }, TetriminoRow{ { 0,1,1,1 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	else if (t == Type::Z) {
		mGrid = TetriminoGrid{ TetriminoRow{ { 0,0,0,0 } }, TetriminoRow{ { 1,1,0,0 } }, TetriminoRow{ { 0,1,1,0 } }, TetriminoRow{ { 0,0,0,0 } } };
	}
	mType = t;
	mColor = c;
}

void Tetrimino::dataDump(std::ostream& stream) {
    stream << "Type: ";
    switch (mType) {
        case Type::J:
            stream << "J\n";
            break;
		case Type::I:
			stream << "I\n";
			break;
        case Type::L:
            stream << "L\n";
            break;
        case Type::O:
            stream << "O\n";
            break;
        case Type::S:
            stream << "S\n";
            break;
        case Type::T:
            stream << "T\n";
            break;
        case Type::Z:
            stream << "Z\n";
            break;
        default:
            stream << "Unknown\n";
    }
    stream << "Color: ";
    switch (mColor) {
        case Color::Red:
            stream << "Red\n";
            break;
		case Color::Yellow:
			stream << "Yellow\n";
			break;
		case Color::Teal:
			stream << "Teal\n";
			break;
		case Color::Orange:
			stream << "Orange\n";
			break;
		case Color::Purple:
			stream << "Purple\n";
			break;
        case Color::Green:
            stream << "Green\n";
            break;
        case Color::Blue:
            stream << "Blue\n";
            break;
        default:
            stream << "Unknown\n";
    }
	stream << "Position: " << mLocation.x << " " << mLocation.y << std::endl;
    stream << "Grid:\n";
    for (auto row:mGrid) {
        for (auto element:row) {
            stream << element << ' ';
        }
        stream << std::endl;
    }
	stream << "#####\n";
}

Tetrimino& Tetrimino::rotateRight() {
	TetriminoGrid newGrid = mGrid;
	int rI = 0, rJ = 0;
	int i = 0, j = 0;
	for (i = 0; i < TETRIMINO_SIZE; i++) {
		for (int j = TETRIMINO_SIZE - 1; j >= 0; j--) {
			newGrid[rI][rJ] = mGrid[j][i];
			rJ++;
		}
		rI++;
		rJ = 0;
	}
	mGrid = newGrid;
	return *this;
}

Tetrimino& Tetrimino::rotateLeft() {
	TetriminoGrid newGrid = mGrid;
	int rI = 0, rJ = 0;
	int i = 0, j = 0;
	for (i = TETRIMINO_SIZE - 1; i >= 0; i--) {
		for (int j = 0; j < TETRIMINO_SIZE; j++) {
			newGrid[rI][rJ] = mGrid[j][i];
			rJ++;
		}
		rI++;
		rJ = 0;
	};
	mGrid = newGrid;
	return *this;
}

Tetrimino& Tetrimino::moveUp() {
	mLocation.x--;
	return *this;
}
Tetrimino& Tetrimino::moveDown() {
	mLocation.x++;
	return *this;
}
Tetrimino& Tetrimino::moveLeft() {
	mLocation.y--;
	return *this;
}
Tetrimino& Tetrimino::moveRight() {
	mLocation.y++;
	return *this;
}

Location Tetrimino::getLocation() const {
	return mLocation;
}
void Tetrimino::setLocation(Location l) {
	mLocation = l;
}
void Tetrimino::setLocation(int x, int y) {
	setLocation(Location{ x,y });
}

Tetrimino::Color Tetrimino::getColor() const {
	return mColor;
}

void Tetrimino::setColor(Tetrimino::Color c)
{
	mColor = c;
}

Tetrimino::Type Tetrimino::getType() const{
	return mType;
}


TetriminoGrid Tetrimino::getGrid() const {
	return mGrid;
}



