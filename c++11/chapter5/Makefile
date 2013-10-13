tuple_io : tuple_io.o
	g++ -o tuple_io  tuple_io.o

tuple_io.o : tuple_io.h tuple_io.cpp
	g++ -Wall -g -std=c++0x -c tuple_io.cpp tuple_io.h 

cleanup:
	rm tuple_io.o tuple_io
