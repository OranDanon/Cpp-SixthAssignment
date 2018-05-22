#pragma once

#ifndef IllegalCharException_H
#define IllegalCharException_H
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class IllegalCharException : public invalid_argument
{
private:
	char m_c;
	const char* m_msg;

public:
	IllegalCharException(const char c, const char* msg);
	char theChar()const;
};

#endif // IllegalCoordinateException_H