#include "Board.h"
using namespace std;

bool Board::checkValidIndex(int index) const
{
	return (index >= 0) && (index < m_size);
}

/**
* Constructor
* */
Board::Board(size_t size) : m_size(size)
{
	this->m_a = new char[size * size];
	for (size_t i = 0; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size; j++)
		{
			m_a[i*m_size +j] = Board::param.empty;
		}
	}
}

/**
* Overloaded assignment operator;
* const return avoid (b1 = b2) = b3
*/
const Board& Board::operator=(const Board& other)
{
	if (this != &other) // Avoid self-assignment
	{
		//for Arrays of different sizes, deallocate original
		//left-side Array, then allocate new left-side Array
		if (this->m_size != other.m_size)
		{
			delete[] m_a;// realse space
			m_size = other.m_size;//resize this object
			m_a = new char[m_size * m_size];//create spcae for array
		}

		for (size_t i = 0; i < m_size*m_size; i++)
		{
			//copy array 
			m_a[i] = other.m_a[i];
		}
	}
	return *this;
}

/**
 * Assignment operator overloading
*/
const Board & Board::operator=(const char & c)
{
	if (!this->m_a)
	{
		throw invalid_argument("Board is not initialized");
	}
	if (c != '.' && c != 'X' && c != 'O')
	{
		throw IllegalCharException(c, "Invalid Charcter");
	}
	for (size_t i = 0; i < m_size * m_size; i++)
	{
			m_a[i] = c;
	}
	return *this;
}

/**
 * subscripting operator overloading
 */
char& Board::operator[](std::pair<size_t, size_t> index) const
{
	size_t indx = index.first * m_size + index.second;
	size_t size = m_size * m_size;
	// check for subscript out-of-range error
	if (indx < 0 || indx > size)
	{
		throw IllegalCoordinateException(index, "Out of range");
	}
	return this->m_a[indx];
}

char& Board::operator[](std::pair<size_t, size_t> index)
{
	size_t indx = index.first * m_size + index.second;
	// check for subscript out-of-range error
	if (!Board::checkValidIndex(index.first) || ! Board::checkValidIndex(index.second))
	{
		throw IllegalCoordinateException(index, "Out of range");
	}
	return this->m_a[indx];
}

/*
 * Destructor
 */
Board::~Board()
{
	delete[] m_a;
}

ostream & operator<<(ostream & os, const Board & b)
{
	string st = "";
	for (size_t i = 0; i < b.m_size; i++)
	{
		for (size_t j = 0; j < b.m_size; j++)
		{
			os << b.m_a[i*b.m_size + j];
		}
		os << endl;
	}
	os << endl;
	return os;
}
