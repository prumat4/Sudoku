#include <iostream>
#include <set>
#include <vector>


using namespace std;

class Sudoku 
{
    int size;
    vector<vector<char>> board;

    bool isValidPlace(const int& row, const int& col,const char& number);
    bool solver();
    bool isValidSudoku();

    // leetcode
    // runtime: 32ms, 
    // memory usage: 6.5 mb

public:
    
    void print();
    void solveSudoku();

    Sudoku();
    Sudoku(vector<vector<char>> temp);
};