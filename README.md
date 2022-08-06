# Welcome Play Sudoku Here

## To boost the game:
./sudoku 

## Input a 9 * 9 unsolved sudoku. 
## eg: 

------7-- \
-6-3----- \
------5-1 \
-8-4---3- \
--------- \
--1--5--8 \
---63--4- \
--2------ \
5-7------ 

## It has functions: fill, hint, choices, reset, erase, solve, print. 
### Try solve the Sudoku yourselves:
$>       fill [row] [col] num
    
### "hint" will display a cell that only has one possible answer:
$>       hint
    
### When there is not a cell that with only one possible answer, try use "choices":
$>       choices [row] [col]
### this shows all possilbe answers for this cell.

### Fill something wrong? Don't worry about it, use "erase" to erase a anser:
$>       erase [row] [col]
  
### Or just "reset" the Sudoku:
$>       reset

### You might want to look at the current state use "print":
$>       print 
    
### Unalbe to solve it? :(  
### Do not worry let it solve it for you:
$>       solve



