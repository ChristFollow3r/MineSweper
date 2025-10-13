
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
        std::cout << "How many rows do you want the game to have (min 2, max 10): "; // If the user enters a char the game will break.
        std::cin >> rows;

        std::cout << "How many columns do you want the game to have (min 2, max 10): "; // If the user enters a char the game will break.
        std::cin >> columns;

        do
        {
            std::cout << "How many mines do you want in the grid (only as much as spaces the grid has please): "; 
            std::cin >> mines; // If the user enters 1 billion mines the game will break.

        } while (mines > rows * columns || mines <= 0);

    } while (rows > 10 || rows < 2 || columns > 10 || columns < 2);

    //Create the grid.
    
    for (int i = 0; i < rows; i++)  // This defines the grid.
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = '#';
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
  
    for (size_t placedMines = 0; placedMines < mines;) // I should've done this with a while loop but its already done so it's staying like this cause it's my little baby :)

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
        switch (i) // Ask the teacher (should I not do this switch (since chat gpt told me I could've just did (char whatever = 'a' + i) std::cout << "Whatever";) or keep it cause it's my little baby).
        {
        case 0:
            break;
        case 1:
            std::cout << "b";
            break;
        case 2:
            std::cout << "c";
            break;
        case 3:
            std::cout << "d";
            break;
        case 4:
            std::cout << "e";
            break;
        case 5:
            std::cout << "f";
            break;
        case 6:
            std::cout << "g";
            break;
        case 7:
            std::cout << "h";
            break;
        case 8:
            std::cout << "i";
            break;
        case 9:
            std::cout << "j";
            break;
        }
         
        for (size_t j = 0; j < columns; j++)
        { 
            while (iThinkINeedABoool == true)
            {
                for (size_t h = 0; h < columns; h++)
                {
                    if (h == 0)
                    {
                        std::cout << " ";
                    }

                    std::cout << h;
                }
                std::cout << std::endl;
                std::cout << "a";
                iThinkINeedABoool = false;
                continue;
            }
            std::cout << visibleGrid[i][j];
        }

        std::cout << std::endl; // So far so good :)

    }
   
    // Reveal mines mechanic.
    // The user can't play the game!
    // Show all mines at the end.
    
    // Enough for today :V





} 

