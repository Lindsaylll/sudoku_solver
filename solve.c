#include "solve.h"
bool solve(struct sudoku *s)
{
    // every row
    for (int i = 0; i < 9; ++i)
    {
        int arr[9] = {};
        for (int j = 0; j < 9; ++j)
        {
            int pos = i * 8 + j;
            int tmp = (s->puzzle)[pos];
            if (arr[tmp] != 0)
            {
                return false;
            }
            else
            {
                arr[tmp] = 1;
            }
        }
    }

    // every col
    for (int i = 0; i < 9; ++i)
    {
        int arr[9] = {};
        for (int j = 0; j < 9; ++j)
        {
            int pos = i + j*9;
            int tmp = (s->puzzle)[pos];
            if (arr[tmp] != 0)
            {
                return false;
            }
            else
            {
                arr[tmp] = 1;
            }
        }
    }

    // every box
    int arr[9] = {};
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            int pos = 
        }
    }
}
