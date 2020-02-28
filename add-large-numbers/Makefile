CC=clang++
CFLAGS=-c -Wall -g --std=c++11
SRC=$(wildcard *.cc)
OBJS=$(SRC:.cc=.o)
EXE=nums

.PHONY: all clean

all: build

build: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXE)

 %.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f $(EXE)
