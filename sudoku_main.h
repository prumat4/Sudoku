#include "sudoku.h" 

Sudoku::Sudoku() 
{   
    size = 9;
    for(int i = 0; i < size; i++) 
    {
        board.push_back(vector<char> (size));
    }

    for(int i = 0; i < size; i++) 
    {   
        for(int j = 0; j < size; j++) 
        {
            board.at(i).at(j) = 46;
        }   
    }
}

Sudoku::Sudoku(vector<vector<char>> tempBoard) 
{   
    size = 9;
    
    for(int i = 0; i < size; i++) 
    {
        board.push_back(vector<char> (size));
    }

    for(int i = 0; i < size; i++) 
    {   
        for(int j = 0; j < size; j++) 
        {
            this->board.at(i).at(j) = tempBoard.at(i).at(j);
        }   
    }
}

void Sudoku::print() 
{   
    cout << "-------------------------------\n";
    for(int i = 0; i < board.size(); i++) 
    {
        for(int j = 0; j < board.size(); j++) 
        {
            cout << board[i][j] << " ";
        }   
        cout << endl;
    }
    cout << "-------------------------------\n";
}

bool Sudoku::isValidSudoku() 
{
    bool ans = true;

    set<char> temp;
    int number_of_zeros = 0; // zeros ~ '.'

    for(int i = 0; i < board.size(); i++) 
    {
        for(int j = 0; j < board.size(); j++) 
        {
            if(board[i][j] == 46) 
            {
                number_of_zeros++;
            }
            temp.emplace(board[i][j]);
        }

        if(temp.size() != board.size() - number_of_zeros + 1) 
        {
            ans = false;
        }
        temp.clear();
        number_of_zeros = 0;
    }

    if(ans) 
    {
        for(int i = 0; i < board.size(); i++) 
        {
            for(int j = 0; j < board.size(); j++) 
            {
                if(board[j][i] == 46) 
                {
                    number_of_zeros++;
                }
                temp.emplace(board[j][i]);
            }

            if(temp.size() != board.size() - number_of_zeros + 1) 
            {
                ans = false;
            }
            temp.clear();
            number_of_zeros = 0;
        }   
    }

    if(ans) 
    {
        for(int i = 0; i < board.size(); i += 3) 
        {
            for(int j = 0; j < board.size(); j += 3) 
            {
                for(int k = i; k < i + 3; k++) 
                {
                    for(int p = j; p < j + 3; p++) 
                    {
                        if(board[p][k] == 46) 
                        {
                            number_of_zeros++;
                        }
                        temp.emplace(board[p][k]);
                    }
                    
                }
                
                if(temp.size() != board.size() - number_of_zeros + 1) 
                {
                    ans = false;
                }
                
                temp.clear();
                number_of_zeros = 0;
            }
        }

    }

    if(ans == false) 
        cout << endl << "Sudoku is unsolvable :(" << endl;
    
    return ans;
}

bool Sudoku::isValidPlace(const int& row, const int& col,const char& number) 
{
    for(int i = 0; i < board.size(); i++) 
    {
        if(board[row][i] == number) 
        {
            return false;
        }

        if(board[i][col] == number) 
        {
            return false;
        }

        if(board[i/3 + 3*(row/3)][i%3 + 3*(col/3)] == number) 
        {
            return false;
        }
    }
    
    return true;   
}

bool Sudoku::solver() 
{
    for(int i = 0; i < board.size(); i++) 
    {
        for(int j =  0; j < board.size(); j++) 
        {
            if(board[i][j] == '.') 
            {   
                for(char number = '1'; number <= '9'; number++) 
                {
                    if(isValidPlace(i, j, number)) 
                    {
                        board[i][j] = number;

                        if(solver()) 
                        {
                            return true;
                        } else 
                        {
                            board[i][j] = '.';                 
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void Sudoku::solveSudoku() 
{
    print();

    if(isValidSudoku()) 
        solver();

    print();
}

void Sudoku::fillBoard(ifstream& file) 
{
    for (int i = 0; i < board.size(); i++) 
    {
        for(int j = 0; j < board.size(); j++) 
        {
            file >> board.at(i).at(j);
        }
    }     
}

void Sudoku::insertFromFile() 
{
    ifstream inFile;

    inFile.open("validSudokus.txt");

    if(inFile.fail()) 
    {
        cout << endl << "Error opening file :(" << endl;
    }

    fillBoard(inFile);

    inFile.close();
}

void Sudoku::testCases() 
{
    ifstream inFile;

    inFile.open("validSudokus.txt");

    while(true) 
    {
        fillBoard(inFile);
        solveSudoku();
        if(inFile.fail()) 
        {
            cout << endl << "All sudokus are solved OR filing opening the fail" << endl;
            break;
        }
    }

    inFile.close();
}
