CXX=clang++-5.0 -std=c++14Proxy.o: Proxy.cpp Proxy.h
	$(CCX) -c Proxy.cpp

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CCX) -c IllegalCharException.cpp
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CCX) -c IllegalCoordinateException.cpp

Board.o: Board.cpp Board.h
	$(CCX) -c Board.cpp
	
Clean:
	rm *.o a.out