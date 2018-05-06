#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <new>
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
	bool checkValidIndex(int index)const;
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