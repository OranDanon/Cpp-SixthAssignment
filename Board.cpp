#include "Board.h"
#include "Coordinate.h"

using namespace std;

bool Board::checkValidIndex(int index) const
{
	return (index >= 0) && (index < m_size);
}

inline bool Board::exists_test(const std::string & name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

Board::Board():m_size(0), m_a(nullptr)
{
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

Board::Board(const Board & other):m_size(other.m_size)
{
	size_t size = other.m_size;
	this->m_a = new char[size * size];
	for (size_t i = 0; i < m_size*m_size; i++)
	{
		//copy array 
		m_a[i] = other.m_a[i];
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
const char& Board::operator[](std::pair<size_t, size_t> index) const
{
	size_t indx = index.first * m_size + index.second;
	size_t size = m_size * m_size;
	// check for subscript out-of-range error
	if (indx > size)
	{
		throw IllegalCoordinateException(index, "Out of range");
	}
	return this->m_a[indx];
}

Proxy Board::operator[](std::pair<size_t, size_t> index)
{
	size_t indx = index.first * m_size + index.second;
	// check for subscript out-of-range error
	if (!Board::checkValidIndex(index.first) || ! Board::checkValidIndex(index.second))
	{
		throw IllegalCoordinateException(index, "Out of range");
	}
	return Proxy(this->m_a[indx]);
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
istream & operator>>(istream & is, Board & b)
{
	string st("");
	//stringstream ss("");
	is >> st;
	b = Board(st.size());
	for (size_t i = 0; i < b.m_size; i++)
	{
		for (size_t j = 0; j < b.m_size; j++)
		{
			char* location =  &b.m_a[i * b.m_size + j];
			*location = st[j];
			if (*location != '.' && *location != 'X' && *location != 'O')
			{
				throw IllegalCharException(*location, "You explict the faith I gave you :-<");
			}
		}
		if (i != b.size() - 1)
		{
			is >> st;
		}
	}
	return is;
}
const string Board::draw(const int n) const
{
	// Taken from Erel Segal-Halevi git
	const int dimx = n, dimy = n;
	size_t i = 0;
	ostringstream st;
	st << "image" << i << ".ppm";
	while (exists_test(st.str()))
	{
		i++;
		st.str(std::string());
		st << "image" << i << ".ppm";
	}
	ofstream imageFile(st.str(), ios::out | ios::binary);
	imageFile << "P6" << endl << dimx << " " << dimy << endl << 255 << endl;
	RGB* image = new RGB[dimx*dimy];
	if (image == nullptr)
	{
		cerr << "error";
	}
	size_t size = n / m_size;
	for (size_t i = 0; i < m_size; i++)
	{
		for (size_t j = 0; j < m_size; j++)
		{
			switch (m_a[m_size* i + j])
			{
			case 'X':
				for (size_t k = 0; k < size; k++)
				{
					for (size_t l = 0; l < size; l++)
					{
						// The index of the {i,j} in the image is equal to
						// {n * size * i , j * size}
						// Since each entry has size colums and we pass i entries
						// and each entry has size colums and we pass j entries
						// so lets note the new location using (i',j')
						// we ran from (i' ... i' + size) in each row
						// When we go to the next row we pass n entries
						// the claim is follows
						image[n * size * i + j * size + k * n + l].red = 100;  //******//
						image[n * size * i + j * size + k * n + l].green = 248;// Green//
						image[n * size * i + j * size + k * n + l].blue = 173; //******//
					}
				}
				break;
			case 'O':
				for (size_t k = 0; k < size; k++)
				{
					for (size_t l = 0; l < size; l++)
					{
						image[n * size * i + j * size + k * n + l].red = 200;  // ****** //
						image[n * size * i + j * size + k * n + l].green = 162;// Purple //
						image[n * size * i + j * size + k * n + l].blue = 236; // ****** //
					}
				}
				break;
			case '.':
				for (size_t k = 0; k < size; k++)
				{
					for (size_t l = 0; l < size; l++)
					{
						image[n * size * i + j * size + k * n + l].red = 255;  // ******* //
						image[n * size * i + j * size + k * n + l].green = 255;//  White  //
						image[n * size * i + j * size + k * n + l].blue = 255; // ******* //
					}
				}
				break;
			}
		}
	}
	///
	///image processing
	///
	imageFile.write(reinterpret_cast<char*>(image), 3 * n * n);
	imageFile.close();
	delete[] image;
	return st.str();
}