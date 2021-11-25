/* This was my first attemt. I fortot matixes existed. Oh well. I execuded it better in the nedt exercise*/



#include <iostream>

char id[10]= {'0','1','2','3','4','5','6','7','8','9'};

void tablet();
int Checkmate();
   
int main(){
    /*Make a two player tic tac toe game.
    announce when a player has won the game (and which player won, x or o)
    */

    int round = 1;
    char token;
    int choice;
	int player = 1;
    int i;

    do
    {
        tablet();
        player = (player%2)?1:2;

        std::cout << "Player " << player << ", enter a number:  ";
        std::cin >> choice;

        token=(player == 1) ? 'X' : 'O';

        if (choice == 1 && id[1] == '1')

            id[1] = token;
        else if (choice == 2 && id[2] == '2')

            id[2] = token;
        else if (choice == 3 && id[3] == '3')

            id[3] = token;
        else if (choice == 4 && id[4] == '4')

            id[4] = token;
        else if (choice == 5 && id[5] == '5')

            id[5] = token;
        else if (choice == 6 && id[6] == '6')

            id[6] = token;
        else if (choice == 7 && id[7] == '7')

            id[7] = token;
        else if (choice == 8 && id[8] == '8')

            id[8] = token;
        else if (choice == 9 && id[9] == '9')

            id[9] = token;
        else
        {
            std::cout<<"Invalid move ";

            player--;
            std::cin.ignore();
            std::cin.get();
        }
        i=Checkmate();

        player++;
    }while(i==-1);
    tablet();
    if(i==1)

        std::cout<<"==>\aPlayer "<<--player<<" win ";
    else
        std::cout<<"==>\aGame draw";

    std::cin.ignore();
    std::cin.get();
    return 0;
}


void tablet(){

    std::cout << "\n " << id[1] << " | " << id[2] << " | " << id[3] << " "
          << "\n------------"
          << "\n " << id[4] << " | " << id[5] << " | " << id[6] << " "
          << "\n------------"
          << "\n " << id[7] << " | " << id[8] << " | " << id[9] << " \n";

}

int Checkmate(){

     if (id[1] == id[2] && id[2] == id[3])

        return 1;
    else if (id[4] == id[5] && id[5] == id[6])

        return 1;
    else if (id[7] == id[8] && id[8] == id[9])

        return 1;
    else if (id[1] == id[4] && id[4] == id[7])

        return 1;
    else if (id[2] == id[5] && id[5] == id[8])

        return 1;
    else if (id[3] == id[6] && id[6] == id[9])

        return 1;
    else if (id[1] == id[5] && id[5] == id[9])

        return 1;
    else if (id[3] == id[5] && id[5] == id[7])

        return 1;
    else if (id[1] != '1' && id[2] != '2' && id[3] != '3' 
                    && id[4] != '4' && id[5] != '5' && id[6] != '6' 
                  && id[7] != '7' && id[8] != '8' && id[9] != '9')

        return 0;
    else
        return -1;
}
