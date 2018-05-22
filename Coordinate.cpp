#include "Coordinate.h"

Coordinate::Coordinate() : indx({0,0})
{
}

Coordinate::Coordinate(std::pair<size_t, size_t> index) :indx(index)
{
}

const size_t Coordinate::x() const
{
	return this->indx.first;
}
const size_t Coordinate::y() const
{
	return this->indx.second;
}

Coordinate::Coordinate(size_t x, size_t y):indx({x,y})
{
}
Coordinate::operator std::pair<size_t, size_t>() const
{
	return indx;
}
size_t Coordinate::index(const int & size) const
{
	return indx.first * size + indx.second;
}

void Coordinate::print() const
{
	std::cout << "{" << indx.first << ", " << indx.second << "}" << std::endl;
}
