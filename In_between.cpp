#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void mainMenu() {
    cout << "Would you like to bet?" << endl;
    cout << "1.Bet" << endl;
    cout << "2.Skip" << endl;
}

const int SIZE = 50;

struct Players {
    char name[SIZE];
    int playerMoney;
};


int main() {

    int card1, card2, drawedCard, prizePool, playerNum, decision, betAmount;
    int playerTurn = rand();
    int randNumber[2];
    int x;
    string dummy;
    Players *players = new Players[x];


    cout << "Welcome to Simple In-Between Games" << endl;
    cout << "Please insert the number of players: ";
    cin >> playerNum;
    cout << "Please enter the amount of prize pool: RM";
    cin >> prizePool;
    getline(cin,dummy);
    system("CLS");

    //Get player data
    cout << "You will need the following information." << endl;
    for (x = 0; x < playerNum; x++) {
        cout << "Player's ID: " << x << endl;
        cout << "Please enter the Player's Name: ";
        cin.getline(players[x].name, 50);
        players[x].playerMoney = prizePool;
        cout << "Total Amount of Player's Money: RM" << players[x].playerMoney << endl;
        cout << "\n";
    }

    //Declared variables
    int pturn = 0;
    

    
    while (prizePool > 0 || players[x].playerMoney > 0) {

        x = pturn;

        //Show current prize pool amount
        cout << "Current Prize Pool: RM" << prizePool << endl;

        //Player 1 will start the game 
        cout << players[x].name << " Turn" << endl;

        //start the game by giving the player 2 random numbers (between 1 and 13)
        //Draw first number
        srand((unsigned) time(0));
        for (int i = 0; i < 2; i++) {
            randNumber[i] = (rand() % 13) + 1;
        }

        //sort the both random number in ascending order
        if (randNumber[0] > randNumber[1])  {
            
            int temp;
            temp = randNumber[0];
            randNumber[0] = randNumber[1];
            randNumber[1] = temp;
            cout << "First Card: " << randNumber[0] << " Second Card: " << randNumber[1] <<endl;
        }

        else {
            cout << "First Card " << randNumber[0] << " Second Card: " << randNumber[1] <<endl;
        }


        //let player decide want to bet or not
        mainMenu();

        cin >> decision;
        //bet
        if (decision == 1) {

            //let player decide how much they want to bet
            cout << "Money Left: RM" << players[x].playerMoney << endl;
            cout << "How much amount you want to bet? RM";
            cin >> betAmount;
            while (betAmount > players[x].playerMoney) {
                cout << "Please enter a valid amount (Not more than money you have!)" << endl;
                cin >> betAmount;
            }

            // generate a number for player (between 1 and 13)
            cout << "First Card: " << randNumber[0] << endl;
            cout << "In-between: ";
            srand((unsigned) time(0));
            for (int j = 0; j < 1; j++) {
                drawedCard = (rand() % 13) + 1;
                cout << drawedCard << endl;
            }
            cout << "Second Card: " << randNumber[1] << endl;

            if (drawedCard <= randNumber[0] || drawedCard >= randNumber[1]) {
                
                //player money - betAmount && prize pool + betAmount 
                players[x].playerMoney = players[x].playerMoney - betAmount;
                prizePool = prizePool + betAmount;

                //inform player lose
                cout << "\n";
                cout << "You Lose" << endl;
                cout << "\n";
                cout << "Next Player Turn" << endl;
                ++pturn;
                if (pturn >= playerNum) {
                    pturn = 0;
                }
            } 

            else {

                //player money + betAmount && prize pool - betAmount
                players[x].playerMoney = players[x].playerMoney + betAmount;
                prizePool = prizePool - betAmount;

                //inform player win
                cout << "\n";
                cout << "You Win" << endl;
                cout << "\n";
                cout << "Next Player Turn" << endl;
                ++pturn;
                if (pturn >= playerNum) {
                    pturn = 0;
                }
            }

            
        }

        else if (decision == 2) {
            
            //next player turn
            ++pturn;
            if (pturn >= playerNum) {
                pturn = 0;
            }
            system("cls");
        }

        else {            
            //error handling 
            while (decision > 2) {
                cout << "Please select a valid option!" << endl;
                cin >> decision;
            }
        }

    }

    cout << "Game Over" << endl;

    return 0;

}

