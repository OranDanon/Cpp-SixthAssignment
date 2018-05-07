CCX=g++ -std=c++11

a.out: main.o Board.o Proxy.o IllegalCharException.o IllegalCoordinateException.o
	$(CCX) main.o Board.o Proxy.o IllegalCharException.o IllegalCoordinateException.o -o a.out

main.o: main.cpp
	$(CCX) -c main.cpp

Proxy.o: Proxy.cpp Proxy.h
	$(CCX) -c Proxy.cpp

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CCX) -c IllegalCharException.cpp
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CCX) -c IllegalCoordinateException.cpp

Board.o: Board.cpp Board.h
	$(CCX) -c Board.cpp
	
Clean:
	rm *.o a.out