#include "solve.h"
#include "sudoku.h"
#include <stdio.h>
#include "array.h"
// struct sudoku {
//   int puzzle[81];
//   int sol[81];
// };

bool solve(struct sudoku *s)
{

    while (!solved_puzzle(s))
    {
        printf("in solving\n");

        int row, col;
        int rv = next_cell(s, &row, &col);
        if (rv < 0)
        {
            // printf("Could not find a cell with only one possible value\n");
            reset_sol(s);
            return false;
        }
        else
        {
            int choices[9];
            int num_choices = 0;
            choices_cell(s, row, col, choices, &num_choices);
            if (num_choices == 0)
            {
                printf("No possible value for cell (%d,%d)\n", row, col);
                reset_sol(s);
                return false;
            }
            else if(num_choices == 1)
            {
                printf("Cell (%d,%d) could have values", row, col);
                print_array(choices, num_choices);
                fill_cell(s,  row,  col,  choices[0]);
                continue;

            } else{
                printf("To many choices for (%d,%d), could not decide one \n", row, col);
                reset_sol(s);
                return false;
            }
            
        }
    }
    return true;
}
// every row
// for (int i = 0; i < 9; ++i)
// {
//     int arr[9] = {};
//     for (int j = 0; j < 9; ++j)
//     {
//         int pos = i * 8 + j;
//         int tmp = (s->puzzle)[pos];
//         if (arr[tmp] != 0)
//         {
//             return false;
//         }
//         else
//         {
//             arr[tmp] = 1;
//         }
//     }
// }

// // every col
// for (int i = 0; i < 9; ++i)
// {
//     int arr[9] = {};
//     for (int j = 0; j < 9; ++j)
//     {
//         int pos = i + j * 9;
//         int tmp = (s->puzzle)[pos];
//         if (arr[tmp] != 0)
//         {
//             return false;
//         }
//         else
//         {
//             arr[tmp] = 1;
//         }
//     }
// }

// // every box
// int st[] = {0, 3, 6, 27, 30, 33, 54, 57, 60};

// for (int s = 0; s < 9; ++s)
// {
//     int arr[9] = {};
//     int pos = st[s];
//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             pos = pos + i * 9 + j;
//             if(arr[pos] == 0){
//                 arr[pos] = 1;
//             } else{
//                 return false;
//             }

//         }
//     }
// }
// return true;
