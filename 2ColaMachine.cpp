#include <iostream>

int main(){


//set up vars
    int soda;

//Promt and input
    std::cout << "Hey there! Would you like: \nCoca Cola-1 \nPepsi-2 \nDr.Pepper-3 \nDiet Cola-4 \nDiet Pepsi-5\n Input Number BTW!\n";
    std::cin >> soda;

//Results
    if(soda == 1)
        std::cout << "You got Coca Cola!";
    else if(soda == 2)
        std::cout << "You got Pepsi!";
    else if(soda == 3)
         std::cout << "You got Dr.Pepper!";
    else if(soda == 4)
         std::cout << "You got Diet Cola!";
    else if(soda == 5)
        std::cout << "You got Diet Pepsi!";
    else 
        std::cout << "NO! Have your money back :p";
}


/* SWITCH-STATMENT*/
/* switch (soda)
    {
     case(soda == 1)
     std::cout << "You got Coca Cola!";
     break;

     case(soda == 2)
     std::cout << "You got Pepsi!";
     break;

     case(soda == 3)
     std::cout << "You got Dr.Pepper!";
     break;

     case(soda == 4)
     std::cout << "You got Diet Cola!";
     break;

     case(soda == 5)
     std::cout << "You got Diet Pepsi!";
     break;

    default:
    std::cout << "NO! Have your money back :p";
     break;*/