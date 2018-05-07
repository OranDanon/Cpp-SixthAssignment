#include "Proxy.h"

Proxy::Proxy(char & v): myChar(&v)
{
}

Proxy& Proxy::operator=(const char & v)
{
	if (v != 'X' && v != 'O' && v != '.')
	{
		throw IllegalCharException(v, "Only X O and . are allowed");
	}
	*myChar = v;
	return *this;
}

Proxy::operator char() const
{
	return *myChar;
}
