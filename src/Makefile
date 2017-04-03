# Makefile to create test client executable and static library.

CC=gcc
DEBUG=-g
CFLAGS=-Wall -Werror
INCLUDESDIR=../includes/
OBJSDIR=../obj/
LIBSDIR=../lib/
LIBRARY=lib_gagaron.a
BINDIR=../bin/
BINARY=main
LIBFLAGS=-lm
SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c,%.o,$(SRC))

print-%  : ; @echo $* = $($*)

.PHONY:all

all:$(LIBRARY) $(BINARY)
	@echo "Compilation Done."
	mv *.o $(OBJSDIR)
	mv $(LIBRARY) $(LIBSDIR)
	mv $(BINARY) $(BINDIR)

valgrind:
	@echo "--------------------------------------------------------------------------------"
	@echo "Executing the test client to check memory leak"
	@echo "--------------------------------------------------------------------------------"
	@echo "If ERROR is seen, main program has made force EXIT due to error condition"
	@echo "--------------------------------------------------------------------------------"
	valgrind ./../bin/main
	@echo "--------------------------------------------------------------------------------"

$(BINARY):$(OBJ)
	@echo "Creating binary for test client"
	$(CC) -o $@ $^ -lm

$(LIBRARY):$(OBJ)
	@echo "Creating static library- lib_gagaron.a"
	ar rcs $(LIBRARY) $(OBJ) 
		
$(OBJ): $(SRC)
	@echo "COMPILING source files"
	$(CC) $(CFLAGS) $(DEBUG) -I$(INCLUDESDIR) -c $^
	
	
.PHONY: clean
clean:
	@echo "cleaning all binariers,static lib and object files"
	rm -f $(OBJSDIR)*.o
	rm -f $(LIBSDIR)*.a
	rm -f $(BINDIR)*
    
