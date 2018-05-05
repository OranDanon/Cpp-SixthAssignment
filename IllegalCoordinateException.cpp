#include "IllegalCoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(const std::pair<size_t, size_t> index, const char * msg): std::out_of_range(msg), m_index(index),m_msg(msg)
{
}

string IllegalCoordinateException::theCoordinate() const 
{
	ostringstream oss;
	oss << "{" << m_index.first << ", " << m_index.second << "}";
	return oss.str();
}
