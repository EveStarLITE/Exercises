#include <iostream>
#include <ctime>
#include <stdlib.h>

int main(){
    /*Write a program that calculates a random number 1 through 100
        output "too high" or "too low" accordingly.
        The program must let the user continue to guess until the user correctly guesses the number.

★ Modify the program to output how many guesses it took the user to correctly guess the right number.*/

int randNum;
int guessNum;
int guessCount = 0;
std::string high = "Too hight\n";
std::string low = "Too low\n";

srand(time(0));
randNum = rand() % 100 + 1;

std::cout << "What number am I thinking of?" << std::endl;
std::cin >> guessNum;

while (guessNum != randNum) {
    if(guessNum < randNum){

        std::cout << low;

    } else{

        std::cout << high;

    }

        guessCount++;
        std::cout << "Nope- Try again\n";
        std::cin >> guessNum;

}

    std::cout << "You win!\n";
    std::cout << "We played " << guessCount << " times!\n";

}