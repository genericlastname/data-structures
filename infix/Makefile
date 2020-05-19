CC=clang++
CFLAGS=-c -g
SRC=$(wildcard *.cc)
OBJS=$(SRC:.cc=.o)
EXE=infix

.PHONY: all clean

all: build

build: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXE)

 %.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f $(EXE)
