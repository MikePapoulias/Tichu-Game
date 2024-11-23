#include "hand.h"
// TODO: Implement here the method createAllCombinations of Hand

// Here are created all possible combinations that can create a player with he's cards.
void Hand::createAllCombinations(){

    // Here are created all singles-combinations. All cards can be a single combination.
    for(int i=0;i<currentNumberOfCards;i++)
        {
            allCombinations[allCombinationsSize].addCard(cards[i]);
            allCombinationsSize++;
        }


    // Here are created all possible pair-combinations.
    int temp = 1;

    for(int i=0;i<currentNumberOfCards;i++)
    {
        for(int j=temp; j<currentNumberOfCards; j++)
        {
            // Here is checked if two cards have the same value but different suit.
            if(cards[i].getValue()==cards[j].getValue() && cards[i].getSuit()!=cards[j].getSuit())
                {
                    allCombinations[allCombinationsSize].addCard(cards[i]);
                    allCombinations[allCombinationsSize].addCard(cards[j]);
                    allCombinationsSize++;

                    continue;
                }
        }
        // At the end of the second "for", temp increases by one, so that do not occur two identical combinations each time.
        temp++;
    }
}
