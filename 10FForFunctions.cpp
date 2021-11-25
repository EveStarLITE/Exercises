#include <iostream>

void say_Hello(int times);
void multiply(int a, int b);
void half(int vic);

int main(){
    /*Write a function titled say_hello() that outputs to the screen "Hello"

★ Modify the function so that it takes an integer argument and says hello a number of times equal to the value passed to it.

★★ Make another function that takes two integers arguments and then returns an integer that is the product of the two integers.
(i.e., integer1: 4, Integer2: 5 returns: 20)

★★★ Make a function called half() that takes an integer argument. The function must print the number it received to the screen, 
then the program should divide that number by two to make a new number. 
If the new number is greater than zero the function then calls the function half() passing it the new number as its argument. 
If the number is zero or less than the function exits

Call the function half() with an argument of 100, the screen output should be
100
50
25
...
...
1.*/

say_Hello(3);

multiply(4,5);

half(100);

}

void say_Hello(int times){

    for(int max = 0; max < times; max++){
        std::cout << "Hello\n";
    }
}

void multiply(int a, int b){

    int Prod = a * b;
    std::cout << Prod << "\n";

}

void half(int vic){

    std::cout << vic << "\n";

        while(vic > 0){

            vic = vic/2;
            std::cout << vic << "\n";

        }
}