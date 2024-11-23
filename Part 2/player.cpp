#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

// TODO: Implement here the methods of Player
// Do not implement the methods addCardToHand, removeCardFromHand, addCardsToBucket
// createHandCombinations, findNumberOfPlayableCombinations, playAnyCombination, play
// These are already implemented in file playercombinations.cpp
// Implement the rest of the methods of Player

Player::Player(int idx)
{
    index = idx;

    switch(idx)
    {
        case 0:
             name="Player 1";
             break;
        case 1:
             name="Player 2";
             break;
        case 2:
             name="Player 3";
             break;
        case 3:
             name="Player 4";
             break;
    }

    status="HASNTPLAYED";
    // The size of the bucket must be equal to 0.
    bucketSize = 0;
}

void Player::setStatus(string newStatus)
{
    status = newStatus;
}

// Here is checked if the statues of the player is the same as the given one.
bool Player::hasStatus(string checkStatus)
{
    if(status==checkStatus)
        return true;
    else
        return false;
}

string Player::getName()
{
    return name;
}

// Here is checked if the player has no cards left.
bool Player::hasNoCardsLeft()
{
    if (hand.getCardCount()==0)
        return true;
    else
        return false;
}

// Here is checked ho player has the MAHJONG card, so play first.
bool Player::hasMahJong(){

    int x;
    for(int i=0; i<hand.getCardCount(); i++)
    {
        if (hand.getCard(i).getSuit()=="MAHJONG"){
            x=1;
            break;}
    else
        x=0;

    }
    if(x==1)
        return true;
    else
        return false;
}

// Here a player will decide to play or not, with 50-50 probability.
bool Player::decidePlay()
{
    int probability;
    probability = rand() % 2 + 0;

    if (probability==1)
        return true;
    else
        return false;
}
