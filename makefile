# Windows command : mingw32-make au lieu de make

CC = g++
CFLAGS = -Wall -Werror -std=c++11
LDFLAGS =

DEPS = Pizza.h
OBJ = Pizza.o main.o

default: pizza.exe

pizza.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f *.o core
	rm -f *.exe
	rm -f *.txt