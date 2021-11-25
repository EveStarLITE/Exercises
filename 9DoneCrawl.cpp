    /*Make a program that outputs a simple grid based gameboard to the screen using either numbers or characters.
i.e.

. . . . . . . . . .
. G . . . . . . . .
. . . . . . T . . .
. . . . . . . . . .
. . . . T . . . . .
. . . . . . T . . .
. . . . . . . . . X

Allow the user (marked by G in the example) to move either up, down, left, or right each turn. If the player steps on a trap then they lose. 
If the make it to the treasure 'X' then they win.

★★ Add enemies that move randomly in any direction once per turn. (enemies just like traps cause the player to lose if touched)

HINT: Don't let the player move off the gameboard! You program will crash if they move off the top or bottom of the board!
(the same holds true for enemies)
*/
#include <iostream>
#include <string>
#include <stdlib.h> 

#define EMPTY '.'

void Tablet(char matrix[10][10]);
bool ifEnd(char matrix[10][10], int i, int j);
int psudoAI(char matrix[10][10], int i, int j);

class gamePiece
{
public:
    int IthCord;
    int JthCord;
    char ID;

};
//Setting up Starting values for all game pieces

int main(){

//Difine all game pices as they are all valued members in this dungon
gamePiece Gamer;
    Gamer.ID = 'G';
    Gamer.IthCord = 0;
    Gamer.JthCord = 0;
gamePiece Trap1;
    Trap1.ID = 'T';
    Trap1.IthCord = rand() % 9 + 0;
    Trap1.JthCord = rand() % 9 + 0;
gamePiece Trap2;
    Trap2.ID = 'T';
    Trap2.IthCord = rand() % 9 + 0;
    Trap2.JthCord = rand() % 9 + 0;
gamePiece Trap3;
    Trap3.ID = 'T';
    Trap3.IthCord = rand() % 9 + 0;
    Trap3.JthCord = rand() % 9 + 0;
gamePiece Enemey1;
    Enemey1.ID = 'E';
    Enemey1.IthCord = rand() % 9 + 0;
    Enemey1.JthCord = rand() % 9 + 0;
gamePiece Enemey2;
    Enemey2.ID = 'E';
    Enemey2.IthCord = rand() % 9 + 0;
    Enemey2.JthCord = rand() % 9 + 0;
gamePiece tresure;
    tresure.ID = 'x';
    tresure.IthCord = 9;
    tresure.JthCord = 9;
    
//Important vars
char Matrix[10][10];
char Move;
int change;

//inizialise the Matrix
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        Matrix[i][j] = EMPTY;
    }//End loop 1
}//end loop 2

//set bored
    Matrix[Gamer.IthCord][Gamer.JthCord] = Gamer.ID;

    Matrix[tresure.IthCord][tresure.JthCord] = tresure.ID;

    Matrix[Trap1.IthCord][Trap1.JthCord] = Trap1.ID;
    Matrix[Trap2.IthCord][Trap2.JthCord] = Trap2.ID;
    Matrix[Trap3.IthCord][Trap3.JthCord] = Trap3.ID;

    
    Matrix[Enemey1.IthCord][Enemey1.JthCord] = Enemey1.ID;
    Matrix[Enemey2.IthCord][Enemey2.JthCord] = Enemey2.ID;

srand (time(NULL));
    
    Tablet(Matrix);

//While the gamer isn't on another bit that isn't the tresuse
while(ifEnd(Matrix, Gamer.IthCord, Gamer.JthCord) == true){

    std::cout << "Your move (WASD)\n";
    Matrix[Gamer.IthCord][Gamer.JthCord] = EMPTY; 
    std::cin >> Move;

//I don't have a joystick so rig one up
    switch (Move){
    case 'w':
        if(Gamer.IthCord == 0){
            Gamer.IthCord = 9;
        }else {
            Gamer.IthCord--;
        };
        break;
    case 's':
         if(Gamer.IthCord == 9){
            Gamer.IthCord = 0;
        }else {
            Gamer.IthCord++;
        };
        break;
    case 'a':
        if(Gamer.JthCord == 0){
            Gamer.JthCord = 9;
        }else {
            Gamer.JthCord--;
        };
        break;
    case 'd':
        if(Gamer.JthCord == 9){
            Gamer.JthCord = 0;
        }else {
            Gamer.JthCord++;
        };
        break;
    default:
        break;
    }//End of switch 1

//if the play meets the win condition
    if(Matrix[Gamer.IthCord][Gamer.JthCord] == 'x'){

        Matrix[Gamer.IthCord][Gamer.JthCord] = Gamer.ID;
        Tablet(Matrix);
        std::cout << "You won!\n";
        std::exit(0);

//if the play has not won but not died yet
    }else if(ifEnd(Matrix, Gamer.IthCord, Gamer.JthCord)){

        Matrix[Gamer.IthCord][Gamer.JthCord] = Gamer.ID;
        change = psudoAI(Matrix, Enemey1.IthCord, Enemey1.JthCord);

        switch (change)
        {
        case 1:
            if(Enemey1.IthCord == 9){
                Enemey1.IthCord = 0;
            }else{
                Enemey1.IthCord++;
            }
            break;
        case 2:
            if(Enemey1.IthCord == 0){
                Enemey1.IthCord = 9;
            }else{
                Enemey1.IthCord--;
            }
            break;
        case 3:
            if(Enemey1.JthCord == 9){
                Enemey1.JthCord = 0;
            }else{
                Enemey1.JthCord++;
            }
            break;
        case 4:
            if(Enemey1.JthCord == 0){
                Enemey1.JthCord = 9;
            }else{
                Enemey1.JthCord--;
            }
            break;
        default:
            break;
        }//end of switch 2

            Matrix[Enemey1.IthCord][Enemey1.JthCord] = Enemey1.ID;

        change = psudoAI(Matrix, Enemey2.IthCord, Enemey2.JthCord);


        switch (change)
        {
        case 1:
            if(Enemey2.IthCord == 9){
                Enemey2.IthCord = 0;
            }else{
                Enemey2.IthCord++;
            }
            break;
        case 2:
            if(Enemey2.IthCord == 0){
                Enemey2.IthCord = 9;
            }else{
                Enemey2.IthCord--;
            }
            break;
        case 3:
            if(Enemey2.JthCord == 9){
                Enemey2.JthCord = 0;
            }else{
                Enemey2.JthCord++;
            }
            break;
        case 4:
            if(Enemey2.JthCord == 0){
                Enemey2.JthCord = 9;
            }else{
                Enemey2.JthCord--;
            }
            break;
        default:
            break;
        }//end of switch 3
            Matrix[Enemey2.IthCord][Enemey2.JthCord] = Enemey2.ID;

            Tablet(Matrix);

            }//End of if statment
        }//End of while loop
    std::cout << "You lost, loser!\n";
    std::exit(1);

}//End of main

//function to print out the borad map
void Tablet(char matrix[10][10]){

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            std::cout << matrix[i][j] << "    ";
        std::cout << "\n\n";
    }
}

//Check if gamer was killed
bool ifEnd(char matrix[10][10], int i, int j){

    if(matrix[i][j] == 'T' || matrix[i][j] == 'E' ){
        return false;
    
    }else{
        return true;
    }
}

//Movment for the enemies
int psudoAI(char matrix[10][10], int i, int j){

    matrix[i][j] = EMPTY;

    int die = rand() % 4 + 1;
    if(die == 1){
        i++;
        return 1;
    }else if(die == 2){
        i--;
        return 2;
    }else if(die ==  3){
        j++;
        return 3;
    }else{
        j--;
        return 4;
    }

}