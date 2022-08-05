#ifndef solve_h
#define solve_h

#include <stdbool.h>
#include "sudoku.h"



// solve(s) solves the Sudoku puzzle by search and backtracking.  
// It mutates the 
// It returns true if s has a valid solution to the puzzle, 
// and returns false otherwise.
// effects: mutates *s
// bool solveRow(struct sudoku *s);
// bool solveCol(struct sudoku *s);
// bool soveCell(struct sudoku *s);
bool solve(struct sudoku *s);

#endif 