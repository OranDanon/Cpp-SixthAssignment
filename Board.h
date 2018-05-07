#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h> 
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
	Proxy* m_ptr;
	size_t proxy_counter;
	size_t prx_cap;
	size_t m_size;
	char* m_a;
	/*
	 * Check that the index is valid, that means that the characters is only one of the following: 'X', 'O', '.'
	*/
	bool checkValidIndex(int index)const;
	/*
	 * Copy the Proxy array from board b2, to board b1.
	*/
	static void copyProxies(Board& b1, const Board& b2);

public:
	Board(size_t x);
	const Board& operator=(const Board& other);
	const Board& operator=(const char& c);
	friend ostream& operator<< (ostream& os, const Board& c);
	char& operator[](std::pair<size_t, size_t> index) const;
	Proxy& operator[](std::pair<size_t, size_t> index);
	~Board();
};

#endif // BOARD_H