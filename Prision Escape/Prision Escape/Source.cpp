#include <iostream>
#include <ctime>
//Simple Code Combination Game
void PrintIntrodution(int Difficulty)
{
    //Printing on Terminal Function
    std::cout << "\n\nYou are a Prisoner, You need to escape from this Level " << Difficulty;
    std::cout << " TOP SECURITY PRISION\nYou need to unlock the doors using the correct key combinations...\n";
}
bool PlayGame(int Difficulty)
{

    PrintIntrodution(Difficulty);
    //Declaration Tab
    const int KeyA = rand() % Difficulty + Difficulty;
    const int KeyB = rand() % Difficulty + Difficulty;
    const int KeyC = rand() % Difficulty + Difficulty;
    const int Total_Sum_Of_Keys = KeyA + KeyB + KeyC;
    const int Total_Product_Of_Keys = KeyA * KeyB * KeyC;
    //Total Output Tab
    std::cout << std::endl;
    std::cout << "There are 3 numbers you need to guess to open the key combination...\n";
    std::cout << "The sum of those three numbers add-up to: " << Total_Sum_Of_Keys;
    std::cout << "\nAnd it multiplies to get: " << Total_Product_Of_Keys << std::endl;

    //Taking Player input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Decision making statements
    if (GuessSum == Total_Sum_Of_Keys && GuessProduct == Total_Product_Of_Keys)
    {
        std::cout << "\nAwesome! You won this level. Moving to next Level\n";
        return true;
    }
    else
    {
        std::cout << "\nINCORRECT CODE! You are Caught!!!!!  RETRY!!!!!\n";
        return false;
    }
}
int main()
{
    srand(time(NULL)); //Creates new random statements based upon the time of the day
    int LevelDifficulty = 1;
    int const MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel) //Loops till player completes all levels
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   //Clears any errors
        std::cin.ignore();  //Discards the buffers
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\nCONGRATULATIONS!!!! YOU WON THE GAME\n";
    return 0;
}