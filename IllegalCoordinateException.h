#ifndef IllegalCoordinateException_H
#define IllegalCoordinateException_H
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class IllegalCoordinateException: public out_of_range
{
private:
	std::pair<size_t, size_t> m_index;
	const char* m_msg;

public:
	IllegalCoordinateException(const std::pair<size_t, size_t> index, const char* msg);
	string theCoordinate()const;
};

#endif // IllegalCoordinateException_H