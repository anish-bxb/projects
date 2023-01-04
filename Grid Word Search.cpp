


//===================================================================================
//Anish Banswada
//October 2022
//This program will read in a puzzle as a grid and a list of words to find, and prints 
// the locations of those words.
//===================================================================================
#include <iostream>
#include <iomanip>
using namespace std;
//===================
//function declarations
//===================
const int M = 14;
int coordinates[] = { -1,-1, 0, 1, 1, 1, 0, -1, 0, 1, 1, 1, 0, -1, -1, -1 };
bool found;
void read ( char G[M][M] );
void print ( char G[M][M] );
bool search (char grid[M][M], int row, int col, int index, string word, int k);
//=================
//main function
//=================
int main ( void )
{
    char grid[M][M];
    int word_number;
    read(grid);
    print(grid);
    
    cin >> word_number;
    string word;
    for (int h = 0; h < word_number; h++)
    {
        found = false;
        cin >> word;
        for (int i = 0; i < M && found == false; i++)
        {
            for (int j = 0; j < M && found == false; j++)
            {
                if (word[0] == grid[i][j])
                {
                    for (int k = 0; k < 8 && found == false; k++)
                    {
                        search(grid, i + coordinates[k], j + coordinates[k + 8], 1,
word, k);
                        
                    }
                }
            }
        }
        if (found == false)
            cout << word << " not found";
    }
    
    
    return 0;
}
//====================
//read function
//we can use this for inputting a character grid by a MxM 2D array.
//PRARMRTERS:
// - G : a 2D array of characters of M rows and M cols
// RETURN:
// none but the elements in G are changed by inputting the information
//===================
void read ( char G[M][M] )
{
    for ( int i = 0; i < M; i++ )
    {
        for ( int j = 0; j < M; j++ )
        {
            cin >> G[i][j];
        }
    }
    
}
//=====================
//print function
//print a 2D array of the character grid.
//PRARMRTERS:
// - G : a 2D array of integers of M rows and M cols
// RETURN:
// none but this function prints the character gird on the screen
//=====================
void print ( char G[M][M] )
{
    for ( int i = 0; i < M; i++ )
    {
        for ( int j = 0; j < M; j++ )
        {
            cout << setw(4) << G[i][j];
        }
        cout << endl;
    }
    
}
//=====================
//search function
//search the word in the puzzzle and cout the position of this word first time show
up 
//PRARMRTERS:
// - G : a 2D array of integers of M rows and M cols
// - row : a value of row number that we are currently checking
// - col : a value of column number that we are currently checking
// - index : a position number of letter that we are checking in the string word
// - word : a string word we want to find in the puzzle
// - k : a counting number for find the correct directions information in the 
global list of coordinates
// RETURN:
// - True : if we find the word with a direction in the puzzle
// - False : if we cannot find the word in this puzzle
//=====================
bool search(char grid[M][M], int row, int col, int index, string word, int k)
{
    //up
    if (index == word.size() && coordinates[k] == -1 && coordinates[k+8] == 0)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going up" << endl;
        
        found = true;
        return true;
    }
    
    //up right
    if (index == word.size() && coordinates[k] == -1 && coordinates[k+8] == 1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going up right" << endl;
        
        found = true;
        return true;
    }
    
    //right
    if (index == word.size() && coordinates[k] == 0 && coordinates[k+8] == 1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going right" << endl;
        
        found = true;
        return true;
    }
    
    //down right
    if (index == word.size() && coordinates[k] == 1 && coordinates[k+8] == 1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going down right" << endl;
        
        found = true;
        return true;
    }
    
    //down
    if (index == word.size() && coordinates[k] == 1 && coordinates[k+8] == 0)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going down" << endl;
        
        found = true;
        return true;
    }
    
    //down left
    if (index == word.size() && coordinates[k] == 1 && coordinates[k+8] == -1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going down left" << endl;
        
        found = true;
        return true;
    }
    
    //left
    if (index == word.size() && coordinates[k] == 0 && coordinates[k+8] == -1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going left" << endl;
        
        found = true;
        return true;
    }
    
    //up left
    if (index == word.size() && coordinates[k] == -1 && coordinates[k+8] == -1)
    {
        cout << word << " found at (" << row - ((index)*coordinates[k]) << "," << 
col - ((index)*coordinates[k + 8]) << ") " << "going up left" << endl;
        
        found = true;
        return true;
    }
    
    if (row >= 0 && row < M && col >= 0 && col < M)
    {
        if (grid[row][col] == word[index])
        {
            index++;
            search(grid, row + coordinates[k], col + coordinates[k + 8], index, 
word, k);
        }
        else
            return false;
    }
    return false;
}

