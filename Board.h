#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <new>
#include <exception>
#include <iostream>
#include <sys/stat.h>
#include <string>

#include "Proxy.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

#define INIT 10

using namespace std;

struct RGB {
	uint8_t red, green, blue;
public:
	RGB(): red(255), green(255), blue(255) {}
	RGB(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
};

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
	inline static bool exists_test(const std::string& name);

public:
	Board(size_t x);
	Board(const Board& other);
	const Board& operator=(const Board& other);
	const Board& operator=(const char& c);
	friend ostream& operator<< (ostream& os, const Board& b);
	friend istream& operator>> (istream& is, const Board& b);
	const char& operator[](std::pair<size_t, size_t> index) const;
	Proxy operator[](std::pair<size_t, size_t> index);
	const size_t size()const;
	const bool isFull() const;
	const bool isEmpty()const;
	const bool clear();
	const bool draw(const int n) const;
	~Board();
};

#endif // BOARD_H