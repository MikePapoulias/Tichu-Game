#include "player.h"

// TODO: Implement here the methods combinationCanBePlayed and countBucketPoints of Player
// Do not implement any other methods of Player as these are already implemented in file playercombinations.cpp

// This function computes and returns the number of points of the cards in the player's bucket.
int Player::countBucketPoints()
{
    int val=0; // The total points initializes to zero.
    for(int i=0; i<bucketSize; i++)
    {
        if(bucket[i]->getValue()==5)
            val += 5;
    }
    for(int i=0; i<bucketSize; i++)
    {
        if(bucket[i]->getValue()==10 || bucket[i]->getValue()==13)
            val += 10;
    }
    for(int i=0; i<bucketSize; i++)
    {
        if(bucket[i]->getSuit()==DRAGON)
            val += 25;
    }
    for(int i=0; i<bucketSize; i++)
    {
        if(bucket[i]->getSuit()==PHOENIX)
            val -= 25;
    }

    // Here is the total points of each player at the end of the game.
    return val;
}


// This function checks if the current combination can be played after the last combination.
bool Player::combinationCanBePlayed(Combination *current, Combination *last)
{
    int x=0;

    // Here are all the possible combinations that can be played by the next player.
    if(current->getType()==last->getType() && current->getNumberOfCards()==last->getNumberOfCards() && current->getValue()>last->getValue())
        x=1;

    else if(current->getType()==FOUROFAKIND && last->getType()!=FOUROFAKIND)
        x=2;

    else if(current->getType()==STRAIGHTFLUSH && last->getType()!=STRAIGHTFLUSH)
        x=3;

    else  if(current->getType()==FOUROFAKIND && last->getType()!=STRAIGHTFLUSH)
        x=4;

    else  if(current->getType()==STRAIGHTFLUSH && last->getType()!=FOUROFAKIND)
        x=5;

    else  if(current->getType()==STRAIGHTFLUSH && last->getType()==FOUROFAKIND)
        x=7;

    else  if(current->getType()==STRAIGHTFLUSH && last->getType()==STRAIGHTFLUSH && current->getNumberOfCards() > last->getNumberOfCards())
        x=8;

    else
        x=0;


    if(x)
        return true;
    else
        return false;
}
