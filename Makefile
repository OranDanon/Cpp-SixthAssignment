CCX=g++ -std=c++11

Board.o: Board.cpp Board.h IllegalCharException.h IllegalCoordinateException.h
	$(CCX) -c Board.cpp

Proxy.o: Proxy.cpp Proxy.h
	$(CCX) -c Proxy.cpp

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CCX) -c IllegalCharException.cpp
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CCX) -c IllegalCoordinateException.cpp