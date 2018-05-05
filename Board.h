#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <iostream>
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

class Board
{

private:
	const static struct param { enum  parameters{ empty = '.', X = 'X', O = 'O' }; }param;
	size_t m_size;
	char* m_a;
	bool checkValidIndex(int index)const;

public:
	Board(size_t x);
	const Board& operator=(const Board& other);
	const Board& operator=(const char& c);
	friend ostream& operator<< (ostream& os, const Board& c);
	char& operator[](std::pair<size_t, size_t> index) const;
	char& operator[](std::pair<size_t, size_t> index);
	~Board();
};

#endif // BOARD_H