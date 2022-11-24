#include <iostream>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

class Sudoku 
{
    int size;
    vector<vector<char>> board;

    bool isValidPlace(const int& row, const int& col,const char& number);
    bool solver();
    bool isValidSudoku();
    
    void fillBoard(ifstream& file);
    void appendBoardToFile(ofstream& file);

    // leetcode
    // runtime: 32ms, 
    // memory usage: 6.5 mb

public:
    
    void print();
    void solveSudoku();
    
    void insertFromFile();
    void writeInFile();
    
    void Tests(); 

    Sudoku();
    Sudoku(vector<vector<char>> temp);
};