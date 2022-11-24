#include "sudoku_main.h" 

int main() 
{

#define FF
#ifdef FF 

#endif

    Sudoku a;

    a.insertFromFile();
    a.solveSudoku();
    a.writeInFile();
    
    a.Tests();    
    
    return 0;
}