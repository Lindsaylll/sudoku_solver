# Welcome Play Sudoku Here

## To boost the game:
``` Bash
./sudoku 
```

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
``` Bash
fill [row] [col] num
```
    
### "hint" will display a cell that only has one possible answer:
``` Bash
hint
```
    
### When there is not a cell that with only one possible answer, try use "choices":
``` Bash
choices [row] [col]
```
### this shows all possilbe answers for this cell.

### Fill something wrong? Don't worry about it, use "erase" to erase a anser:
``` Bash
erase [row] [col]
```
  
### Or just "reset" the Sudoku:
``` Bash
reset
```

### You might want to look at the current state use "print":
``` Bash
print 
```
    
### Unalbe to solve it? :(  
### Do not worry let it solve it for you:
``` Bash
solve
```



