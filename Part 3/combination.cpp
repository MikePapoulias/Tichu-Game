#include "combination.h"
#include <iostream>
// TODO: Implement here the methods of Combination and all derived classes

Combination::Combination()
{     };

// Here is initialized the combination with it's cards, it's type and it's number of cards.
Combination::Combination(Card** cards, CombinationType type, int numberOfCards)
{
    this->cards = cards;

    this->type = type;
    this->numberOfCards = numberOfCards;
}

Combination::~Combination()
{
    delete [] cards;
}

Card* Combination::getCard(int index)
{
    return cards[index];
}

// Here is checked whether the combination contains the card that is given as a parameter.
bool Combination::containsCard(Card* card)
{
    int i;
    int x;

    for(i=0; i<numberOfCards; i++)
    {
      if(cards[i]->getValue()==card->getValue() && cards[i]->getSuit()==card->getSuit())
        {
            x=1;
            break;
        }
      else x=0;
    }

    if(x)
        return true;
    else
        return false;
}

CombinationType Combination::getType()
{
    return type;
}

// Here is checked whether type of the combination is the same as the one given.
bool Combination::hasType(CombinationType type)
{
     if(this->type == type)
        return true;
     else
        return false;
}

int Combination::getValue()
{
    return value;
}

int Combination::getNumberOfCards()
{
    return numberOfCards;
}

// Here is checked if this combination is equal to the combination given.
bool Combination::equals(Combination* otherCombination)
{
    int check=0; // This is just a check parameter initializes to zero.
    if(numberOfCards==otherCombination->getNumberOfCards())

    for(int i=0;i<numberOfCards;i++)
    {
        if(cards[i]->equals(otherCombination->cards[i]) )
            check++; //check parameter increases by one if the two combinations have the same type as well as the same cards.
    }

    if(numberOfCards==otherCombination->getNumberOfCards() && type == otherCombination->type && check==numberOfCards)
        return true;
    else
        return false;
}

// Here is initialized the SINGLE combination.
Single::Single(Card* card):Combination()
{
    type = SINGLE;
    numberOfCards = 1;

    // This is the value of the combination:
    value = card->getValue();

    cards = new Card*[1];
    cards[0] = card;
}

// Here is initialized the PAIR combination.
Pair::Pair(Card* card1, Card* card2):Combination()
{
    type = PAIR;
    numberOfCards = 2;

    // This is the value of the combination:
    value = card1->getValue();

    cards = new Card*[2];
        if(!cards) cout<<"Error allocating memory";
    cards[0] = new Card(card1->getValue(), card1->getSuit());
    cards[1] = new Card(card2->getValue(), card2->getSuit());
}

// Here is initialized the THREEOFAKIND combination.
ThreeOfAKind::ThreeOfAKind(Card* card1, Card* card2, Card* card3):Combination()
{
    type = THREEOFAKIND;
    numberOfCards = 3;

    // This is the value of the combination:
    this->value = card1->getValue();

    cards = new Card*[3];
        if(!cards) cout<<"Error allocating memory";
    cards[0] = new Card(card1->getValue(), card1->getSuit());
    cards[1] = new Card(card2->getValue(), card2->getSuit());
    cards[2] = new Card(card3->getValue(), card3->getSuit());
}

// Here is initialized the STAIRS combination.
Stairs::Stairs(Card** cards, int numberOfCards):Combination()
{
    type = STAIRS;
    this->numberOfCards = numberOfCards;

    this->cards = cards;

    // This is the value of the combination:
    this->value =cards[numberOfCards-1]->getValue();
}

// Here is initialized the FULLHOUSE combination.
FullHouse::FullHouse(ThreeOfAKind* combination1, Pair* combination2):Combination()
{
    this->type = FULLHOUSE;
    this->numberOfCards = 5;
    this->cards = new Card *[5];

    this->cards[0] = new Card(combination1->getCard(0)->getValue(), combination1->getCard(0)->getSuit());
    this->cards[1] = new Card(combination1->getCard(1)->getValue(), combination1->getCard(1)->getSuit());
    this->cards[2] = new Card(combination1->getCard(2)->getValue(), combination1->getCard(2)->getSuit());
    this->cards[3] = new Card(combination2->getCard(0)->getValue(), combination2->getCard(0)->getSuit());
    this->cards[4] = new Card(combination2->getCard(1)->getValue(), combination2->getCard(1)->getSuit());

    // This is the value of the combination:
    this->value = 10 * combination1->getCard(0)->getValue()+ combination2->getCard(0)->getValue();
}

// Here is initialized the STRAIGHT combination.
Straight::Straight(Card** cards, int numberOfCards):Combination()
{
    type = STRAIGHT;
    this->numberOfCards = numberOfCards;

    this->cards = cards;

    // This is the value of the combination:
    value = cards[numberOfCards-1]->getValue();
}

// Here is checked whether all cards of this straight have the same suit.
bool Straight::cardsHaveTheSameSuit()
{
    int check = 0;
    for(int i=0; i<(numberOfCards-1); i++)
    {
        if(cards[i]->getSuit() == cards[i+1]->getSuit())
            check ++;
    }

    if (check == numberOfCards-1)
        return true;
    else
        return false;
}

// Here is initialized the FOUROFAKIND combination.
FourOfAKind::FourOfAKind(Card* card1, Card* card2, Card* card3, Card* card4):Combination()
{
    type = FOUROFAKIND;
    numberOfCards = 4;

    // This is the value of the combination:
    this->value = card1->getValue();

    cards = new Card*[4];
        if(!cards) cout<<"Error allocating memory";
    cards[0] = new Card(card1->getValue(), card1->getSuit());
    cards[1] = new Card(card2->getValue(), card2->getSuit());
    cards[2] = new Card(card3->getValue(), card3->getSuit());
    cards[3] = new Card(card4->getValue(), card4->getSuit());
}

// Here is initialized the STRAIGHTFLUSH combination.
StraightFlush::StraightFlush(Straight* combination):Combination()
{
    this->type = STRAIGHTFLUSH;
    this->numberOfCards = combination->getNumberOfCards();

    this->cards = new Card * [combination->getNumberOfCards()];
    for(int i=0; i<combination->getNumberOfCards(); i++)
    {
        this->cards[i] = new Card(combination->getCard(i)->getValue(), combination->getCard(i)->getSuit());
    }

    // This is the value of the combination:
    this->value=combination->getValue();
}
