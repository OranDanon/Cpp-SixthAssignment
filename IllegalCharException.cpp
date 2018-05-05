#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(const char c, const char * msg) : std::invalid_argument(msg), m_c(c), m_msg(msg)
{
}

char IllegalCharException::theChar() const
{
	return m_c;
}
