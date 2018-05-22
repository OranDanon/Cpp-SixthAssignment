#pragma once
#ifndef Coordinate_H
#define Coordinate_H
#include <stdio.h>
#include <iostream>
#include <vector>
using std::pair;
using std::vector;

class Coordinate 
{
private:
	std::pair<size_t, size_t> indx;

public:
	Coordinate();
	Coordinate(pair<size_t, size_t> index);
	const size_t x() const;
	const size_t y() const;
	Coordinate(size_t x, size_t y);
	operator pair<size_t, size_t>() const;
	size_t index(const int& size) const;
	void print() const;
};
#endif //Coordinate_H
