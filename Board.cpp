#include "Board.h"
#include "Coordinate.h"

using namespace std;

bool Board::checkValidIndex(int index) const
{
	return (index >= 0) && (index < m_size);
}

void Board::copyProxies(Board & b1, const Board& b2)
{
	if (&b1 == &b2)
	{
		throw exception();
		//throw exception("Cannot copy the same board to itself");
	}
	if (b1.prx_cap != b2.prx_cap)
	{
		b1.prx_cap = b2.prx_cap;
		//free(b1.m_ptr);
		b1.m_ptr = (Proxy*)malloc(sizeof(Proxy)*b2.prx_cap);
	}
	for (size_t i = 0; i < b2.proxy_counter; i++)
	{
		b1.m_ptr[i] = b2.m_ptr[i];
	}
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
	prx_cap = INIT;
	m_ptr = (Proxy*)malloc(sizeof(Proxy)*INIT);
	// m_ptr = new Proxy[INIT];
	// Equavivalent to m_ptr = new Proxy[Init], just need to define defualt constructor
	if (!m_ptr)
	{
		throw bad_alloc();
	}
	proxy_counter = 0;
}

Board::Board(const Board & other):m_size(other.m_size)
{
	size_t size = other.m_size;
	this->m_a = new char[size * size];
	prx_cap = INIT;
	m_ptr = (Proxy*)malloc(sizeof(Proxy)*INIT);
	//m_ptr = new Proxy[INIT];
	// Equavivalent to m_ptr = new Proxy[Init], just need to define defualt constructor
	if (!m_ptr)
	{
		throw bad_alloc();
	}
	proxy_counter = 0;
	for (size_t i = 0; i < m_size*m_size; i++)
	{
		//copy array 
		m_a[i] = other.m_a[i];
	}
	Board::copyProxies(*this, other);
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
			//delete[] m_a;// realse space
			m_size = other.m_size;//resize this object
			m_a = new char[m_size * m_size];//create spcae for array
		}

		for (size_t i = 0; i < m_size*m_size; i++)
		{
			//copy array 
			m_a[i] = other.m_a[i];
		}
		Board::copyProxies(*this, other);
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
const char& Board::operator[](std::pair<size_t, size_t> index) const
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

Proxy & Board::operator[](std::pair<size_t, size_t> index)
{
	size_t indx = index.first * m_size + index.second;
	// check for subscript out-of-range error
	if (!Board::checkValidIndex(index.first) || ! Board::checkValidIndex(index.second))
	{
		throw IllegalCoordinateException(index, "Out of range");
	}
	if (prx_cap == proxy_counter)
	{
		prx_cap += INIT;
		realloc(this->m_ptr, prx_cap);
		if (!m_ptr)
		{
			throw bad_alloc();
		}
	}
	m_ptr[proxy_counter] = Proxy(this->m_a[indx]);
	proxy_counter++;
	return m_ptr[proxy_counter-1];
}


const size_t Board::size() const
{
	return this->m_size;
}

const bool Board::isFull() const
{
	for (size_t i = 0; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size; j++)
		{
			if ((*this)[{i,j}] == '.')
			{
				return false;
			}
		}
	}
	return true;
}

const bool Board::isEmpty() const
{
	for (size_t i = 0; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size; j++)
		{
			if ((*this)[{i, j}] != '.')
			{
				return false;
			}
		}
	}
	return true;
}

const bool Board::clear()
{
	for (size_t i = 0; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size; j++)
		{
			m_a[i*m_size + j] = Board::param.empty;
		}
	}
	return true;
}

/*
 * Destructor
 */
Board::~Board()
{
	delete[] m_a;
	//free(m_ptr);
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
	return os;
}
