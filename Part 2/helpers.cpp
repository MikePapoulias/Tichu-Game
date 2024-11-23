#include "helpers.h"
#include "player.h"

int numberOfPlayersThatHaveNoCardsLeft(Player players[]){
    // TODO: Implement this function

    // Here is returned the number of players that have no cards left.
    int num=0;
    for(int i=0; i<4; i++)
    {
        if (players[i].hasNoCardsLeft())
            num++;
    }
    return num;
}

// Here checked whether the last three players have "PASSED" or have no cards left.
bool lastThreePlayersPassedOrHaveNoCardsLeft(Player players[], int playerTurn){
    // TODO: Implement this fun

    int i;
    int x=0;
    for(i=0;i<4;i++){
        // Here is checked if "i" is different from "playerTurn".
        if(i!=playerTurn)
            if((players[i].hasStatus("PASSED") || players[i].hasNoCardsLeft()))
            x++;
    }

    if(x==3)
        return true;
    else
        return false;
}
