#include "combination.h"
#include <iostream>
#include <cstring>

using namespace std;

// TODO: Implement here the methods of Combination

// Here it is initialized a new combination with 0 cards.
Combination::Combination()
{
    numberOfCards = 0;
    cards[0].setSuit("");
    cards[1].setSuit("");
    cards[0].setValue(0);
    cards[1].setValue(0);
}

// Here a card is added to the combination.
void Combination::addCard(Card card)
{   if(numberOfCards==0){
        cards[0].setSuit(card.getSuit());
        cards[0].setValue(card.getValue());
        numberOfCards++;}
    else{
        cards[1].setSuit(card.getSuit());
        cards[1].setValue(card.getValue());
        numberOfCards++; }
}

Card Combination::getCard(int index)
{
    return cards[index];
}

// Here the value of the higher card is stored to the combination's value.
int Combination::getValue()
{
    int value;

    if (cards[1].getValue() > cards[0].getValue())
        value = cards[1].getValue();
    else
        value = cards[0].getValue();

    return value;
}

int Combination::getNumberOfCards()
{
    return numberOfCards;
}

// Here is checked if this combination can be played after a given combination.
bool Combination::canBePlayed(Combination last)
{
    int value;
    value = cards[0].getValue();

    if (cards[1].getValue() > cards[0].getValue())
        value = cards[1].getValue();

    if (last.getNumberOfCards() == numberOfCards  &&  last.getValue() < value )
        return true;
    else
        return false;
}
