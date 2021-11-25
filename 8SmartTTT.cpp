    /*one player game against the computer (with the computer making its moves randomly)
    Modify so that the computer will block w/ an x) Not smart
    */

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>

bool checkwin(char matrix[3][3],int i, int j,char choice);
int Odds(char matrix[3][3],int i, int j,char choice);
void tablet(char matrix[3][3]);

int main(){

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
bool winCon; 
int toss;
int v = 1;//Initialise the the variable v, increment till 9 to cover all the elements of the matrix

bool Win = false;//To check the chance of win of system

int Gamer_Odds = 0;//To check the chance of win of user and accordingly system will put his move
int My_Odds;//to check the chance of a computer win

tablet(matrix);

srand(time(NULL));
toss = rand()%2;

if(toss){
    winCon = true;
    std::cout << "Gamer Wins the Toss\n";
}
else{
    winCon = false;
    std::cout << "I Win the Toss\n";
}


std::cout << "For Gamer the token is 'o'\n";
std::cout << "For me the token is 'x'\n";



while(v <= 9){

int i, j;// "i" is for the row coordinate and "j" is for the column coordinate- ooo

    if(winCon == true){// If user win's the toss
        std::cout << "Yours turn\n";
        std::cout << "Enter the row coordinate: ";
        std::cin >> i;
        i--;//For user convenience i th coordinate
        std::cout << "Enter the column coordinate: ";
        std::cin >> j; 
        j--;//For user convenience jth coordinate
        if(matrix[i][j] != 'x' && matrix[i][j] != 'o')
            matrix[i][j] = 'o';//Put the user move
        else{
            std::cout << "Already Occupied\n"; //Warn user to fill the blank space
            continue;//Don't count this in "variable v" means don't increment the variable "v"
                    //as it was invalid move
        }

        // After three attempts it will check , this code is for system
        if(v > 2)
            Gamer_Odds = Odds(matrix,i,j,'o');//User chance of win

        //checkwin whether game is over i.e whether user win
        if(v>4){
            if(checkwin(matrix,i,j,'x')){
                std::cout << "\n\tGamer win\n\tCongrats Well played\n";
                tablet(matrix);
                return 0;
            }
         }

        winCon = false;// Let the System play next move
        tablet(matrix);//display the matrix
        std::cout << "\nWait! My turns\n";
    }

    else{//System's Turn
        if(Win == true){//Chance of System of winning
            j = My_Odds%10;//get the j coordinate
            i = My_Odds/10;//get the i coordinate
            //cout<<"System chance win i = "<<i<<" j = "<<j<<endl;

            /*If Structure of Check whether place is empty for winning the system*/
            if(matrix[i][j]!= 'x' && matrix[i][j] != 'o'){//Is place is empty
                matrix[i][j] = 'x';
                if(checkwin(matrix,i,j,1)){
                    tablet(matrix);//Display the current scenerio of the game
                    std::cout << "Sorry You loose !! I win\n";
                    return 0;
                }//end if structure of check win
            }
            else//Means space is occupied by user, and chance of winning by system is lost
                Win = false;//Now let the system to defense the user's move
            /*Ends If Structure of Check whether place is empty for winning the system*/
        }

        if(Win == false){
            if(Gamer_Odds != 0){//If User is going to win , warn the system
                j = Gamer_Odds%10;//get the j coordinate
                i = Gamer_Odds/10;//get the i coordinate
                //cout<<"User chance win i = "<<i<<" j = "<<j<<endl;
            }
            else{
                if(v == 9){//There is no point to check random number if none is winning at the end
                        std::cout << "\t\tGame draw\n";
                        return 0;
                }
                srand(time(NULL));
                i = rand()%3; //random i coordinate
                srand(time(NULL));
                j = rand()%3; //random j coordinate
            }
            /*If System turn's of writting*/
            if(matrix[i][j] != 'x' && matrix[i][j] != 'o')
                matrix[i][j] = 'x';
            else
                continue;
            /*End If Structure of writting system turn's*/
        }//end If Structure is sytem chance of win = false

        if(v > 2){// This condition is necessary to avoid irrevelant check
            My_Odds = Odds(matrix,i,j,'o'); //System chance of win
            if(My_Odds == 0){
                    Win = false;
                    std::cout << "\n Imma loss \n";
            }
            else{
                Win = true;
                std::cout << "\n Imma win \n";
            }
        }
        else{
            My_Odds = 0;
            Win = false;
        }

        winCon = true;//Let the user play his next move
        tablet(matrix);

    }
v++;
}//end of while v<9

return 0;
}

//Display the matrix, oo
void tablet(char matrix[3][3])

{
    int row = 1;
    std::cout << " 1  2  3 \n";
    for(int i = 0; i < 3; i++){
        std::cout << row  << " ";
        for(int j = 0; j < 3; j++)
            std::cout << matrix[i][j] << "|";
        std::cout << "\n   _____\n";
        row++;
    }
}

//Funtion to handle the logic
int Odds(char matrix[3][3],int i, int j,char choice){

int result = 0;//This variale is used to return the required position
char other_choice;//This variable is used for other choice of the variable choice
int count1 = 0;//This variable is used to check the count upto 2

//swap swap
if(choice == 'o')
    other_choice = 'x';
else
    other_choice = 'o';

    //Smart stuff I can't explain but makes sence
    if(i == j){

        for(int k = 0; k < 3; k++){
//logic
            if(matrix[k][k] == choice)
                count1++;

            if(count1 == 2){   //is going to win condition via logic for a /
                for(int k = 0; k < 3; k++){

                    if(matrix[k][k] != choice && matrix[k][k]!= other_choice){
                        int temp = k;
                        temp=temp*10;
                        result=temp+k;
                        return result;
                    }
                }
            }
        }//for loop ends here
    }//If Structure ends here

count1=0; //Reinitilize the count to zero


    //Backwards of what I did before
    for(int m = 0, n = 2; m < 3, n >= 0; m++, n--){
        if(matrix[m][n] == choice){
            count1++;
        }

        if(count1==2){   // is going to win condition via logic for a '\'
        for(int mc = 0, n = 2; m < 3, n >= 0; m++, n--){
                if(matrix[m][n] != choice && matrix[m][n] != other_choice){
                    int temp = m;
                    temp = temp*10;
                    result = temp+n;
                    return result;
                }
            }
        }//End of If structure
    }//End for loop

count1=0; //Reinitilize the count to zero

    //Row logic
    for(int k = 0; k < 3; k++){
        if(matrix[i][k] == choice)
            count1++;

        if(count1==2){   // Row win for either brain
            for(int k = 0; k < 3; k++){
                if(matrix[i][k] != choice && matrix[i][k] != other_choice){
                    int temp = i;
                    temp = temp*10;//for the i thingy
                    result = temp+k;//for the j thingy
                    return result;//Return the required attribute of i and j
                }
            }
        }
    }//for looop ends here

count1=0; //Reinitilize the count to zero

    //Column logic
    for(int k = 0; k < 3; k++){
        if(matrix[k][j] == choice)
            count1++;

        if(count1 == 2){   // Gamer gonna win
            for(int k = 0;k < 3; k++){
                if(matrix[k][j] != choice && matrix[k][j] != other_choice){
                    int temp=k;
                    temp=temp*10;//for the ith coordinate
                    result=temp+j;//for the jth coordinate
                    return result;//Return the required attribute of i and j
                }
            }
        }
    }//for looop ends here

return result;
}//function ends here

//This function is used to check the win of the system/user
bool checkwin(char matrix[3][3],int i, int j,char choice){
bool winCon = false;//Initialize the chance of win false
int count1 = 0;

    //Diagonal checkwin forward
    if(i == j){
        for(int k = 0; k < 3; k++){
            if(matrix[k][k] == choice){
                count1++;
            }
            if(matrix[k][k] != 'x' && matrix[k][k] != 'o')
                break;
        }

        if(count1 == 3)//Means all diagonal elements are equal
            winCon = true;
    }

    //If the Diaganoal Forward is same then return
    if(winCon = true){
        std::cout<<"Win!\n";
        return winCon;
    }

    //Reverse Diagonal checkwin
    for(int m = 0, n = 2; m < 3, n >= 0; m++, n--){
        if(matrix[m][n] != 'x' && matrix[m][n] != 'o' || matrix[m][n] != choice){
            winCon = false;//If diagonal is not same
            break;
        }
         winCon = true;
    }

    //If the Reverse Diaganoal Forward is same then return
    if(winCon = true){
        std::cout << "Win!\n";
        return winCon;
    }

    //Row checkwin
    for(int k=0;k<3;k++){
        if(matrix[i][k] != 'x' && matrix[i][k] != 'o' || matrix[i][k] != choice){
            winCon = false;// Row is not same
            break;
         }
         winCon = true;
    }
    //If row is same then return
    if(winCon = true){
        std::cout<<"Win\n";
        return winCon;
    }

    //Column checkwin
    for(int k = 0; k < 3; k++){
        if(matrix[k][j] != 'x' && matrix[k][j] != 'o' || matrix[k][j] != choice){
            winCon = false; //Column is not same
            break;
         }
         winCon = true;
    }
    //If the Column is same then return
    if(winCon = true){
        std::cout<<"Win\n";
        return winCon;
    }


    return winCon;//return the result false result i.e there is no chance of win
                //as we have checked all the conditions
}