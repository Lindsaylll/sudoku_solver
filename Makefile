CC=gcc
CFLAGS=-I.
DEPS = solve.h sort.h array.h sudoku.h trace.h
OBJ = Main.o solve.o sort.o array.o sudoku.o trace.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sudoku: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)