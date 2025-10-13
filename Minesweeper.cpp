
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int rows;
    int columns;
    int mines;
    const int maxRows = 10;
    const int maxColumns = 10; 
    char grid[maxRows][maxColumns];
    char visibleGrid[maxRows][maxColumns]; 

   
    // Ask the user how many rows and columns.
    do
    {
        std::cout << "How many rows do you want the game to have (min 2, max 10): ";
        std::cin >> rows;

        std::cout << "How many columns do you want the game to have (min 2, max 10): ";
        std::cin >> columns;

        do
        {
            std::cout << "How many mines do you want in the grid (only as much as spaces the grid has please): "; // Fix this (if the user enters more bombs than space has the grid the game will break).
            std::cin >> mines;

        } while (mines > rows * columns || mines == 0);

    } while (rows > 10 || rows < 2 || columns > 10 || columns < 2);

    //Create the grid.
    
    for (int i = 0; i < rows; i++)  // This defines the grid I think.
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = '#'; //Bruh
        }

    }

    // Visible grid

    for (int i = 0; i < rows; i++)  
    {
        for (int j = 0; j < columns; j++)
        {
           visibleGrid[i][j] = '#'; 
        }

    }

    //Nukes

    std::srand(time(0)); 
  
    for (size_t placedMines = 0; placedMines < mines;) // I should've done this with a while loop but its already done so it's staying like this

    {
            int x = rand() % rows;
            int y = rand() % columns;

        if (grid[x][y] != '*')

        {
            grid[x][y] = '*'; 
            placedMines++;
        }      

    }
    
    // This prints the grid!
    bool iThinkINeedABoool = true;

    for (size_t i = 0; i < rows; i++) 
    {
       
         
        for (size_t j = 0; j < columns; j++)
        { 
            while (iThinkINeedABoool == true)
            {
                for (size_t h = 0; h < columns; h++)
                {
                    std::cout << h + 1;
                }
                std::cout << std::endl;
                iThinkINeedABoool = false;
                continue;
            }
            std::cout << visibleGrid[i][j];
        }
        std::cout << std::endl; // So far so good :)
    }
    
    // I think I did not
    // I have to make a row of numbers and a row of letters above the grid so the player can properly check for mines.
    // Reveal mines mechanic.
    // The user can't play the game!
    // Show all mines at the end.
    
    // Enough for today :V





} 

