#include <iostream>
#include <string>

int main(){
/*asks the user to enter any number other than 5
if 5 then exit the program.

after 10 iterations- you win." and exit.

enter any # other than the # equal to the number of times they've been asked to enter a #*/


//set up vars
int numOfInters = 1;
int input;
char newGame;

//promt and input
    std::cout << "Input a number that isn't 5!\n";
    std::cin >> input;

//while both are true then keep playing
while((input != 5) && (numOfInters < 10))

    {numOfInters++; 
    std::cout << "Input another number that isn't 5!\n";
    std::cin >> input;
    std::cout << "We've played " << numOfInters << " rounds!\n";}

//if 5 you lose
if(input == 5)

    std::cout << "NO! Good bye-\n";

//program gets board after 10 rounds
else if(numOfInters >= 10)

    std::cout << "Nah, I'm bored, you've done the thing ten times.\nYou win, kk?\n";
    std::cout << "Want to play a new game?(Y/N) ";
    std::cin >> newGame;

    toupper(newGame);

//case chooser for forever game
    switch (newGame)
    {
        //no
    case 'N':

        std::cout << "Bye then-";

        break;
    
        //yes
    case 'Y':
//new prompt and input
        std::cout << "Yay! Okay Input a number not equal to the times use played: ";
        std::cin >> input;
        numOfInters++;

//increment and keep playing (Ester egg if non-num is entered)
        while(input != numOfInters)

            {
            std::cout << "Nice! Go again- ";
            std::cin >> input;
            numOfInters++;
            }
//end sequances
        if(input == numOfInters)

            std::cout << "ugh you suck! Bye loser ";

    default:

        std::cout << "Bye!";

        break;
    }
}