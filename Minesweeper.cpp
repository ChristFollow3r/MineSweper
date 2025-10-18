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
        std::cout << "How many rows do you want the game to have (min 2, max 10). If you enter a character the program will break! : "; // If the user enters a char the game will break.
        std::cin >> rows;

        std::cout << "How many columns do you want the game to have (min 2, max 10) If you enter a character the program will break!: "; // If the user enters a char the game will break.
        std::cin >> columns;

        do
        {
            std::cout << "How many mines do you want in the grid (only as much as spaces the grid has please): ";
            std::cin >> mines; // If the user enters 1 billion mines the game will break.
            std::cout << "\n";

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

    // Count how many mines are around each cell. 

    int mineCount = 0;

    for (int i = 0; i < rows; i++) // This will check for every index in the array // Add a read.txt me here for the teacher
    {
        mineCount = 0;

        for (int j = 0; j < columns; j++) // Same
        {
            mineCount = 0;

            for (int x = i - 1; x < i + 2; x++) // Now makes more sense. So it will check (lets say i and j is 1) -> [0][1] [1][1] [2][1]
            {
                for (int y = j - 1; y < j + 2; y++) // Same
                {
                    if (grid[i][j] == '*') // This because we don't want to check if there are mines around mines, since if the user checks an index where there's a mine he'll die (not irl).

                    {
                        continue;
                    }


                    else
                    {
                        if (x < 0 || x >= rows || y < 0 || y >= columns)
                        {
                            continue;
                        }

                        else if (grid[x][y] == '*') // This is checking if indexs around the grid[i][j] are bombs (I Think). If x or y are out of bounds it won't do the counting.
                        {

                            mineCount++;

                            // Now we gotta display this number when the user checks an index where there's no bomb.
                        }



                    }
                }
            }

            if (mineCount > 0)

            {
                grid[i][j] = mineCount + '0'; // Chat gpt told me to + 0 
            }

            else if (mineCount == 0)
            {
                grid[i][j] = '.';
            }

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

    bool alive = true;
    int uColumn;
    char uRow;
    int iNeedACounter = 0;

    while (alive)
    {
        std::cout << "\n";

        do
        {
            std::cout << "Enter the column: ";
            std::cin >> uColumn;

        } while (uColumn < 0 || uColumn >= columns);

        do
        {
            std::cout << "Enter the row: ";
            std::cin >> uRow;
            std::cout << "\n";

        } while (uRow < 97 || uRow >= 97 + rows);

        if (grid[uRow - 97][uColumn] == '*') // Chat gpt told me that I did this backwards so now it's as it should be.
        {
            std::cout << "You're dead!\n";
            std::cout << "\n";

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    std::cout << grid[i][j];
                }std::cout << "\n";

            }

            std::cout << "\n";

            alive = false;
        }


        else if (grid[uRow - 97][uColumn] != '*')  // I think now
        {

            visibleGrid[uRow - 97][uColumn] = grid[uRow - 97][uColumn];  // Making changes
            iNeedACounter++;

            if (iNeedACounter == (columns * rows) - mines)
            {
                std::cout << "You win!";
                std::cout << "\n";
                alive = false;
            }

            iThinkINeedABoool = true;

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

        }


    }





    std::cout << "No more playing for you! Go touch some grass."; // I really dont want to do another loop, so no more playing.
    std::cout << "\n";

    // I used IA to help me spot errors in my code, but not to fix them (at least so far).


}