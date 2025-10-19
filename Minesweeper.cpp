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
        std::cout << "How many rows do you want the game to have (min 2, max 10). If you enter a character the program will break! : "; // If the user enters something that's not an int the game will break.
        std::cin >> rows;

        std::cout << "How many columns do you want the game to have (min 2, max 10) If you enter a character the program will break!: "; // If the user enters something that's not an int the game will break.
        std::cin >> columns;

        do
        {
            std::cout << "How many mines do you want in the grid (only as much as spaces the grid has please): "; // If the user enters something that's not an int the game will break.
            std::cin >> mines; 
            std::cout << "\n";

        } while (mines > rows * columns || mines <= 0);

    } while (rows > 10 || rows < 2 || columns > 10 || columns < 2);

    //Create the grid.

    for (int i = 0; i < rows; i++)  // This defines the grid. Each index of grid is filled with a '#'.
    {
        for (int j = 0; j < columns; j++)
        {
            grid[i][j] = '#';
        }

    }

    // Visible grid

    for (int i = 0; i < rows; i++) // Each index of visibleGrid is filled with a '#'.
    {
        for (int j = 0; j < columns; j++)
        {
            visibleGrid[i][j] = '#';
        }

    }

    //Nukes

    std::srand(time(0)); // This generates a "random" seed.

    for (size_t placedMines = 0; placedMines < mines;) // I should've done this with a while loop but its already done so it's staying like this cause it's my little baby :)

    {
        int x = rand() % rows; // We get random positions for the mines (a random position for rows and another for columns). This way the random number stays between the chosen size of the grid.
        int y = rand() % columns;

        if (grid[x][y] != '*') // If the index [x][y] is not a bomb, it places a bomb (this way we dont overwrite bombs).

        {
            grid[x][y] = '*';
            placedMines++; // Put a counter on placedMines so that once placedMines is the same as mines it stops putting mines.


        }

    }

    // Count how many mines are around each cell. 

    int mineCount = 0;

    for (int i = 0; i < rows; i++) // This will check for every index [i] in the array // Add a read.txt me here for the teacher
    {
        mineCount = 0; // Reset the counter so that the mineCount works properly

        for (int j = 0; j < columns; j++) // This will check for every index [j] in the array.
        {
            mineCount = 0; // Reset the counter so that the mineCount works properly

            if (grid[i][j] == '*') // If this index is a mine, the loop starts again.

            {
                continue;
            }

            for (int x = i - 1; x < i + 2; x++) // It will check (lets say i and j is 1) -> [0][1] [1][1] [2][1]
            {
                for (int y = j - 1; y < j + 2; y++) // Same
                {
                    

                        if (x < 0 || x >= rows || y < 0 || y >= columns) // This way we don't check on an index that doesn't exist or its empty.
                        {
                            continue;
                        }

                        else if (grid[x][y] == '*') // This is checking if indexs around the grid[i][j] are bombs, so that we can add the number that tells the user how many mines are around that cell.
                        {

                            mineCount++;

                        }


                }
            }

            if (mineCount > 0)  

            {
                grid[i][j] = mineCount + '0'; // Chat gpt told me to + 0. I still don't understand why I have to add a char and not an int.
            }

            else if (mineCount == 0) // If there aren't mines around it it stays as a '.'.
            {
                grid[i][j] = '.';
            }

        }


    }

    // This prints the grid!

    bool iThinkINeedABoool = true; // Explanation for this bool below when I use it.

    for (size_t i = 0; i < rows; i++)
    {
        switch (i) // I know there's a way of doing this without writing this massive switch, but beacause I dont really understand how it works, I'd rather use this less efficent code (cause I understand it).
        {          // It transforms i (a number from 0 to rows) to a letter, this way we can display the letters as required in the exercise instructions.                  
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
            while (iThinkINeedABoool == true) // This bool will execute once. It prints 'a', then it's set to false so it doesn't print 'a' again.
            {
                for (size_t h = 0; h < columns; h++)
                {
                    if (h == 0) // Im doing this so that when the numbers start getting printed the number is above the first index of the 2D array (if I don't do this the numbers will get displayed the wrong way).
                    {
                        std::cout << " ";
                    }

                    std::cout << h; // This prints the numbers.
                }
                std::cout << std::endl;
                std::cout << "a"; // I got here trough trial and error. With this 'a' gets printed where it needs to be. If I were to add 'a' on the switch it would print above the numbers or at the end of the numbers (something like that).
                iThinkINeedABoool = false;
                continue;
            }
            std::cout << visibleGrid[i][j]; // It prints the visible grid
        }

        std::cout << std::endl; // This makes it so that visibleGrid is properly displayed. If I weren't to add this it would print everything in the same line.

    }

    bool alive = true; // This bool is used to check if the user is still in the game or the game has ended (win or lose).
    int uColumn; 
    char uRow; 
    int revealedCells = 0; // So at first I was doing this counting how many mines (I dont even remember what I was doing, very weird) and chat gpt told me that it was prone to error cause the counter could be cheated, so im counting empty cells now.

    while (alive)
    {
        std::cout << "\n"; 


        do
        {
            std::cout << "Enter the column: "; // Get input
            std::cin >> uColumn;

        } while (uColumn < 0 || uColumn >= columns); // This way the user can't enter an invalid number (anything that's not an int will break the program).

        do
        {
            std::cout << "Enter the row: "; // Get input
            std::cin >> uRow;
            std::cout << "\n";

        } while (uRow < 'a' || uRow >= 'a' + rows); // This way the user can't enter an invalid number (anything that's not an int will break the program).

        if (grid[uRow - 'a'][uColumn] == '*') // Chat gpt told me that I did this backwards so now it's as it should be.
        {
            std::cout << "You're dead!\n";
            std::cout << "\n";

            for (int i = 0; i < rows; i++) // This it to make the grid display bombs and empty cells instead of bombs and numbers.
            {
                for (int j = 0; j < columns; j++)
                {
                    if (grid[i][j] >= '1' &&  grid[i][j] <= '8') // I kinda did this on my own but chat gpt helped me a bit (I made a super long if statemnt for every possible number and ussed || instead of &&):
                    {
                        grid[i][j] = '.'; 
                    }
                    std::cout << grid[i][j];
                }std::cout << "\n"; // This way the grid gets displayed properly.

            }

            std::cout << "\n";

            alive = false; // Player lost.
        }


        else if (grid[uRow - 'a'][uColumn] != '*') 
        {
            system("CLS"); // I added this to make it look like visualGrid was updating itself, but it only deletes what was being displayed on the console.

            if (grid[uRow - 'a'][uColumn] == '.') // If the index the user checks is a '.' (wich it means there aren't bombs around it), it will run the for loops (they display the cells around the '.' cell). 

            {
                for (int x = (uRow - 'a') - 1; x < (uRow - 'a') + 2; x++) // I did this on my own but forgot to subtract 'a' (chat gpt told me)
                {
                    if (x < 0 || x >= rows) // This way we don't check indexs that don't exist, and the program doesn't break.
                    {
                        continue;
                    }

                    for (int y = uColumn - 1; y < uColumn + 2; y++)
                    {
                        if (y < 0 || y >= columns) // This way we don't check indexs that don't exist, and the program doesn't break.
                        {
                            continue;
                        }                     

                        visibleGrid[x][y] = grid[x][y]; // The indexes display now the number of bombs around each index (wich was stored in grid).
                                               
                    }
                }
               
            }

            else if (visibleGrid[uRow - 'a'][uColumn] == '.') // I added this because I was counting mines instead of cells in order to let the user win. It's not necessery but it works just fine.
            {
                std::cout << "You already checked that cell! ";
            }

            visibleGrid[uRow - 'a'][uColumn] = grid[uRow - 'a'][uColumn];  // If this index stored a number inside grid it displays that number.
            

            if (revealedCells == (columns * rows) - mines) // This is necessary in order to make the game winnable. If the user has revealed all the non mine cells he wins.
            {
                std::cout << "You win!";
                std::cout << "\n";

                for (size_t i = 0; i < rows; i++) // Print the grid for the user to see.
                {
                    for (size_t j = 0; j < columns; j++)
                    {
                        std::cout << grid[i][j];
                    }std::cout << "\n";
                }
                alive = false;
            }

            iThinkINeedABoool = true;

            for (size_t i = 0; i < rows; i++) // This displays visibleGrid again.
            {
                switch (i)  
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

                revealedCells = 0; // Aight so sir chat.gpt straight up told me to put this here cause im dumb. This will resset the counter everytime we check the visible grid, that way we don't mess up the counter.

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        if (visibleGrid[i][j] != '#')  //This will check every time inside in visibleGrid if a revealed cell is not a '#', then add a counter to revealedCells. Once revealedCells is equal to (columns * rows) - mines, the player will win.
                        {
                            revealedCells++;
                        }
                    }
                }

                std::cout << std::endl; // So far so good :)

            }
            
        }


    }


    std::cout << "No more playing for you! Go touch some grass."; // I really dont want to do another loop, so no more playing.
    std::cout << "\n";

    // I used AI to help me spot errors in my code, but not to fix them (at least so far).


}