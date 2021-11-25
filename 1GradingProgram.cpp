#include <iostream>

int main(){

//Set up needed vars
int score;

//Promt user and take in input
std::cout << "What score do you have in your programming course?\n";
std::cin >> score;

//if then what
if(score >= 100)
    std::cout << "You are exceding expicatations =D\n";
else if(score >= 90)
    std::cout << "You got an A!\n";
else if(score >= 80)
    std::cout << "You got an B!\n";
else if(score >= 70)
    std::cout << "You got an C!\n";
else if(score >= 60)
    std::cout << "You got an D!\n";
else
    std::cout << "You are failing\n";
}