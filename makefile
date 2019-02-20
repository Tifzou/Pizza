# Windows command : mingw32-make au lieu de make

CC = g++
CFLAGS = -Wall -Werror
LDFLAGS =

DEPS = Pizza.h Slice.h
OBJ = Pizza.o Slice.o

default: pizza.exe

pizza.exe: $(OBJ)
	$(CC) -c -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f *.o core
	rm -f *.exe