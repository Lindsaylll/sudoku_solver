
#include "sort.h"

#include <stdbool.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"
#include "array.h"

const int DIM = 9;
static const int EMPTY = 0;
static const char BLANK = '-';
static const int MIN = 1;
static const int MAX = 9;

static const int SUCCESS = 0;
static const int ERROR = -1;
static const int ERASE_EMPTY_CELL = -2;
static const int ERASE_FILLED_CELL = -3;
static const int ERROR_NEXT_CELL = -4;










static void find_col(int col, int *column) {
  int i = 0;
  while(i < MAX) {
    column[i] = ((MAX * i) + col);
    ++i;
  }
}


static void find_row(int row, int *roww) {
  int i = 0;
  while(i < MAX) {
    roww[i] = ((row * MAX) + i);
    ++i;
  }
}

static void find_box(int row, int col, int *boxx) {
  const int start = (((row / 3) * 27) + ((col / 3) * 3));
  int i = 0;
  while(i < MAX) {
    boxx[i] = (start + ((i / 3) * 9) + (i % 3));
    ++i;
  }
}


// You need to implement the following four functions.

int fill_cell(struct sudoku *s, int row, int col, int num) {
  int column[9] = {0};
  int roww[9] = {0};
  int boxx[9] = {0};
  find_col(col, column);
  find_row(row, roww);
  find_box(row, col, boxx);
  int i = 0;
  while (i < MAX) {
    int n = column[i];
    if (s->sol[n] == num) {
      return ERROR;
    }
    ++i;
  }
  i = 0;
  while (i < MAX) {
    int n = roww[i];
    if(s->sol[n] == num) {
      return ERROR;
    }
    ++i;
  }
  i = 0;
  while (i < MAX) {
    int n = boxx[i];
    if(s->sol[n] == num) {
      return ERROR;
    }
    ++i;
  }
  return 0;
}





void choices_cell(const struct sudoku *s, int row, int col, 
                  int choices[], int *num_choices) {
  struct sudoku s1 = *s;
  *num_choices = 0;
  int a[9] = {MIN, 2, 3, 4, 5, 6, 7, 8, 9};
  int choice_pos = 0;
  int i = 0;
  int pos = DIM * row + col;
  while(i < MAX) {
    int n = a[i];
    if(EMPTY == s1.sol[pos]) {
      if(SUCCESS == fill_cell(&s1, row, col, n)) {
        choices[choice_pos] = n;
        *num_choices += 1;
        ++choice_pos;
      }
    }
    ++i;
  }
}



bool solved_puzzle(const struct sudoku *s) {
  struct sudoku p = *s;
  int i = 0;
  while(i < 81) {
    if(p.sol[i] == EMPTY) {
      return false;
    }
    ++i;
  }
  int n = 0;
  while(n < 81) {
    struct sudoku s1 = p;
    int num = s1.sol[n];
    s1.sol[n] = 0;
    int row = n / 9;
    int col = n % 9;

    int succ = fill_cell(&s1, row, col, num);
    if(succ < 0) {
      return false;
    }
    ++n;
  }
  return true;
}










// There is no need to modify the rest of the functions.

struct sudoku *read_sudoku(void) {
  struct sudoku *s = malloc(sizeof(struct sudoku));
  char c = 0;
  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      scanf(" %c", &c);
      if (c == BLANK) {
        s->puzzle[row * DIM + col] = 0;
      } else {
        s->puzzle[row * DIM + col] = c - '0';
      }
    }
  }

  // copy puzzle to solution
  reset_sol(s);

  return s;
}

void sudoku_destroy(struct sudoku *s) {
  assert(s);
  free(s);
}

void print_sol(const struct sudoku *s) {
  assert(s);

  printf("\n");
  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      int num = s->sol[row * DIM + col];
      if (num == EMPTY) {
        printf("%c", BLANK);
      } else {
        printf("%d", num);
      }  
    }
    printf("\n");
  }
  printf("\n");
}

void reset_sol(struct sudoku *s) {
  assert(s);

  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      s->sol[row * DIM + col] = s->puzzle[row * DIM + col];
    }
  }  
}

// cell_empty(board, row, col) returns true
// if cell (row,col) is empty on board.
// requires: board is a valid sudoku puzzle.
static bool cell_empty(const int board[], int row, int col) {
  assert(board);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);

  return board[row * DIM + col] == EMPTY;
}

int erase_cell(struct sudoku *s, int row, int col) {
  assert(s);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);

  if (cell_empty(s->sol, row, col)) {
    return ERASE_EMPTY_CELL;
  }
  if (!cell_empty(s->puzzle, row, col)) {
    return ERASE_FILLED_CELL;
  }
  s->sol[row * DIM + col] = EMPTY;
  return SUCCESS;
}


int next_cell(const struct sudoku *s, int *row, int *col) {
  assert(s);
  assert(row);
  assert(col);

  int choices[9];
  int num_choices = 0;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (!cell_empty(s->sol, i, j)) continue;
      choices_cell(s, i, j, choices, &num_choices);
      if (num_choices == 1) {
        *row = i;
        *col = j;
        return SUCCESS;
      }
    }
  }
  return ERROR_NEXT_CELL;
}


