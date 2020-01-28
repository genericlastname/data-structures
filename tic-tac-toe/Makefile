CC=clang++
CFLAGS=-c -Wall -g
SRC=$(wildcard *.cc)
OBJS=$(SRC:.cc=.o)
EXE=tic

.PHONY: all clean

all: build

build: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXE)

 %.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f $(EXE)
