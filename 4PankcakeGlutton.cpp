	 /*enter the number of pancakes eaten for breakfast by 10 different people 
Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.

★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
i.e.
Person 4: ate 10 pancakes
Person 3: ate 7 pancakes
Person 8: ate 4 pancakes
...
Person 5: ate 0 pancakes

*/


// Rated M for mature
#include <iostream>
#include <algorithm>
#include <functional>

//Define class
//could have also used structure, but we use class more often so

class Person {

public:
    unsigned id;
    unsigned numPancakes;
    bool operator < (const Person &rhs) {
        return numPancakes < rhs.numPancakes;
    }
};

int main()
{
    Person people[10];
    for (int pep = 0; pep < 10; pep++) {
        people[pep].id = pep+1;
        std::cout << "Enter the number of pancakes eaten by a person "
             << people[pep].id << ": ";
        std::cin >> people[pep].numPancakes;
    }

    std::sort(people, people+10);

std::cout << "Let's see who is going to hell:" << std::endl;
    for (int inter = 10; --inter >= 0;) {
        std::cout << "Person " << people[inter].id << ": ate " << people[inter].numPancakes \
<< " pancakes\n";
    }
}