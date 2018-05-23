#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <cstdlib>
#include <new>
#include <exception>
#include <iostream>
#include "Proxy.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#define INIT 10

using namespace std;


class Board
{

private:
	const static struct param { enum  parameters{ empty = '.', X = 'X', O = 'O' }; }param;
	size_t m_size;
	char* m_a;
	/*
	 * Check that the index is valid, that means that the characters is only one of the following: 'X', 'O', '.'
	*/
	bool checkValidIndex(int index)const;
	/*
	 * Copy the Proxy array from board b2, to board b1.
	*/

public:
	Board(size_t x);
	Board(const Board& other);
	const Board& operator=(const Board& other);
	const Board& operator=(const char& c);
	friend ostream& operator<< (ostream& os, const Board& c);
	const char& operator[](std::pair<size_t, size_t> index) const;
	Proxy operator[](std::pair<size_t, size_t> index);
	const size_t size()const;
	const bool isFull() const;
	const bool isEmpty()const;
	const bool clear();
	~Board();
};

#endif // BOARD_H