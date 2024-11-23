#include "card.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Implement here the methods of Card

Card::Card()
{
    suit="";
    value=0;
}

void Card::setValue(int theValue)
{
    value=theValue;
}

void Card::setSuit(string theSuit)
{
    suit=theSuit;
}

string Card::getSuit()
{
    return suit;
}

// Here it is checked if the suit of the card is the same as the given one.
bool Card::hasSuit(string theSuit)
{
    if(suit==theSuit)
        return true;
    else
        return false;
}

int Card::getValue()
{
    return value;
}

// Here it is checked if the the suit and the value of the card is the same as the given one.
bool Card::equals(Card otherCard)
{
    if(otherCard.getSuit()==suit && otherCard.getValue()==value)
        return true;
    else
        return false;
}

bool Card::canBeInCombination()
{
    if(suit=="DRAGON" || suit=="DOG")
        return false;
    else
        return true;
}

bool Card::canBeInBomb()
{
    if(suit=="MAHJONG" || suit=="DRAGON" || suit=="DOG" ||suit=="PHOENIX")
        return false;
    else
        return true;
}
