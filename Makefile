# Defined macros needed for Makefile
CURR_DIR=$(shell pwd)
CC=g++
CFLAGS=-I$(CURR_DIR)
CFLAGS+=-Wall
CFLAGS+=-std=c++14
FILES=main.cpp
FILES+=datasetUtil.cpp

# Rule for compiling main.cpp with linking path
mainprog: .
	$(CC) $(CFLAGS) $(FILES) -o mainprog $(LIBS)

# Rule for removing executable/obj files
clean:
	rm -f *.o mainprog

# Rule for executing 'mainprog' rule
all: mainprog
