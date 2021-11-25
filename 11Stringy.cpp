#include <iostream>
#include <string>
#include <algorithm>

std::string replace(char vowel, std::string & str);

int main(){
   /* Write a program that asks for a user first name and last name separately.
The program must then store the users full name inside a single string and out put it to the string.

★ Modify the program so that it then replaces every a, e, i , o, u w/ the letter z.

★★ Modify the Program so that it reverses the users name*/

std::string first;
std::string last;
std::string full;

   std::cout << "What's your first name? No caps: ";
   std::cin >> first;
   std::cout << "What's your last name? No caps: ";
   std::cin >> last;

full = first + " " + last;

   std::cout << full << "\n";

    full = replace('a', full);
    full = replace('e', full);
    full = replace('i', full);
    full = replace('o', full);
    full = replace('u', full);

   std::cout << full << "\n";
   std::reverse(full.begin(), full.end());
   std::cout << full;
}

std::string replace(char vowel, std::string & str)
{
    for (char & ch : str){ 
        if (ch  == vowel)
            ch = 'z';
         }
      return str;
}