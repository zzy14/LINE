CC = g++
CFLAGS = -pthread -Ofast
INCLUDES = -I/usr/local/include
LIBS = -L/usr/local/lib


line : line.o randnum.o
	$(CC) $(CFLAGS) -o line line.o randnum.o $(INCLUDES) $(LIBS) 

line.o : line.cpp
	$(CC) $(CFLAGS) -c line.cpp $(INCLUDES) $(LIBS)

randnum.o : randnum.cpp
	$(CC) $(CFLAGS) -c randnum.cpp $(INCLUDES) $(LIBS)

clean :
	rm -rf *.o line
