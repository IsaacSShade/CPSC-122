/*
 Name: Aiden Tabrah
 Class: CPSC 122, Spring 2023
 Date: Febuary 12, 2023
 Programming Assignment: PA3
 Description: Has a player's numbers pre-stored, asks the user for the winning number for this week and checks if the player won.
*/

#include "header.h"

int main() {
    int winningNum = 0;
    int luckyNums[NUM_PLAYER_NUMBERS] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int * luckyNumsPtr = &luckyNums[0];
    bool win = false;
    

    cout << "\nWhat is the winning number for this week? (5 digits)\n";
    cout << " >>";

    cin >> winningNum;

    win = findWinningLotteryTicket(winningNum, luckyNumsPtr, NUM_PLAYER_NUMBERS);

    if (win) {
        cout << endl << "!!! Congragulations, You won the lottery !!!\n\n";
    }
    else {
        cout << endl << "You have not won the lottery, better luck next time!\n\n";
    }

    return 0;
}