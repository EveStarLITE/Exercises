    /*Write a program so that instead of the user guessing a number the computer came up with, 
    the computer guesses the number that the user has secretely decided. The user must tell the computer whether it guesed too high or too low.
    Modify the program so that no matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.*/

#include <iostream>
#include <string>


int main() {
	std::string hint;
	int max = 100;
    int min = 1;
    int tries = 0;
    int number = 0;
	std::cout << "Think of a number between 1 and 100." << std::endl;

	do {
		number = (max + min) / 2;// Algorithm
		std::cout << std::endl << tries + 1 << " computer's guess is " << number << std::endl;
		std::cout << "Is the guess high, low, or correct?: ";
		std::cin >> hint;

		if (hint == "high")
			max = number--;
		else if (hint == "low")
			min = number++;
		tries++;
	} while (tries < 7 && hint != "correct");

	if (tries == 7 && hint != "correct")
		std::cout << "I lost! Congrats!";
	else
		std::cout << "\nThe computer's guess was correct after " << tries << " tries! Woohoo!!!" << std::endl;
	std::cout << "\n\nThanks for playing. Press Enter...\n";
	std::cin.get();
	std::cin.get();
	return 0;
}
