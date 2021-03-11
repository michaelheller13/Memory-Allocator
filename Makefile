
CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

vpath %.h ./include
vpath %.c ./src

EXECS = dlisttest alloc-dlist_test memory-test-1

all: $(EXECS)

doc:
	doxygen

$(OBJ)/dnode.o: dnode.h dnode.c
	$(CC) $(CFLAGS) -c $(SRC)/dnode.c -o $(OBJ)/dnode.o

$(OBJ)/dlist.o: dlist.h dlist.c dnode.h
	$(CC) $(CFLAGS) -c $(SRC)/dlist.c -o $(OBJ)/dlist.o

$(OBJ)/allocator.o: allocator.h allocator.c dnode.h dlist.h
	$(CC) $(CFLAGS) -c $(SRC)/allocator.c -o $(OBJ)/allocator.o

dlisttest: $(SRC)/dlisttest.c $(OBJ)/dnode.o $(OBJ)/dlist.o
	$(CC) $(CFLAGS) $(OBJ)/dnode.o $(OBJ)/dlist.o $(SRC)/dlisttest.c -o $(BIN)/dlisttest

alloc-dlist_test: $(SRC)/alloc-dlist_test.c $(OBJ)/dnode.o $(OBJ)/dlist.o
	$(CC) $(CFLAGS) $(OBJ)/dnode.o $(OBJ)/dlist.o $(SRC)/alloc-dlist_test.c -o $(BIN)/alloc-dlist_test

memory-test-1: $(SRC)/memory-test-1.c $(OBJ)/dnode.o $(OBJ)/dlist.o $(OBJ)/allocator.o
	$(CC) $(CFLAGS) $(OBJ)/allocator.o $(OBJ)/dnode.o $(OBJ)/dlist.o $(SRC)/memory-test-1.c -o $(BIN)/memory-test-1

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~

