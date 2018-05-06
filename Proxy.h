#ifndef Proxy_H
#define Proxy_H
#include "IllegalCharException.h"
class Proxy
{
private:
	char* myChar;
public:
	Proxy(char& v);
	Proxy& operator=(const char& v);
	operator char() const;
};

#endif ///Proxy_H