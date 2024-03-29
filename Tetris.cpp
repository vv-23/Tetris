// Tetris.cpp : Defines the entry point for the console application.
//Tetrimino Rotator v 0.80085
//Author: Vi Vuong


#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Tetrimino.h"
#include "Well.h"

using namespace std;


int main()
{
	ofstream f;
	f.open("Log.txt");
	Well w("Input.txt");

	/*Tetrimino t1(Tetrimino::Type::O);
	Tetrimino t2(Tetrimino::Type::O);
	Tetrimino t3(Tetrimino::Type::O);
	Tetrimino t4(Tetrimino::Type::O);
	Tetrimino t5(Tetrimino::Type::O);
	Tetrimino t6(Tetrimino::Type::O);
	Tetrimino t7(Tetrimino::Type::O);
	Tetrimino t8(Tetrimino::Type::I);
	Tetrimino t9(Tetrimino::Type::I);

	t1.setLocation(-1,21);
	t2.setLocation(1, 21);
	t3.setLocation(3, 21);
	t4.setLocation(5, 21);
	w.addTetrimino(t1);
	w.addTetrimino(t2);
	w.addTetrimino(t3);
	w.addTetrimino(t4);

	t5.setLocation(-1, 18);
	t6.setLocation(1, 18);
	t7.setLocation(3, 18);
	t8.setLocation(5, 17);
	t9.setLocation(4, 17);
	w.addTetrimino(t5);
	w.addTetrimino(t6);
	w.addTetrimino(t7);
	w.addTetrimino(t8.rotateRight());
	w.addTetrimino(t9.rotateRight());*/
	
	w.clearFullRows();
	w.boardDump(f);
	//t1.dataDump(f);
	f.close();
    return 0;
}