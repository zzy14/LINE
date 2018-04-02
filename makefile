CC = g++
CFLAGS = -lm -pthread -Ofast -march=native -Wall -funroll-loops -Wno-unused-result -lgsl -lm -lgslcblas
LFLAGS = -lgsl -lm -lgslcblas
INCLUDES = -I/usr/local/include -I../eigen
LIBS = -L/usr/local/lib


line : line.o randnum.o
	$(CC) $(CFLAGS) -o line line.o randnum.o $(INCLUDES) $(LIBS) $(LFLAGS)

line.o : line.cpp
	$(CC) $(CFLAGS) -c line.cpp $(INCLUDES) $(LIBS) $(LFLAGS)

randnum.o : randnum.cpp
	$(CC) $(CFLAGS) -c randnum.cpp $(INCLUDES) $(LIBS) $(LFLAGS)

clean :
	rm -rf *.o line
