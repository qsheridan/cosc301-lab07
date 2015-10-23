CC=clang
CFLAGS=-g -Wall -pthread
TARGETS=procshare threadshare mtlist problem1

all: $(TARGETS)

procshare: procshare.o
	$(CC) $(CFLAGS) -o $@ procshare.o

threadshare: threadshare.o
	$(CC) $(CFLAGS) -o $@ threadshare.o

mtlist: list.o mtlist.o list.h
	$(CC) $(CFLAGS) -o $@ list.o mtlist.o

problem1: problem1.o
	$(CC) $(CFLAGS) -o $@ problem1.o

.PHONY: clean
clean:
	rm -f *.o $(TARGETS) list.o

.c.o:
	$(CC) -c $(CFLAGS) $<
