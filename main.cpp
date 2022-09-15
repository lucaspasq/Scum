#include<iostream>
#include<string.h>
#include "Card.h"
#include "Player.h"

using namespace std;

enum class Ranks{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

enum class Suits{
    Spades,
    Clubs,
    Diamonds,
    Hearts
};

struct Card {
    Ranks rank;
    Suits suit;
    int faceVal;
};

struct Deck{
    Card card_array[52];

    void initDeck(){
        
        Card tmpCard;
        int cnt = 0;

        for(int i = (int)Suits::Spades; i <= (int)Suits::Hearts; i++){

            for(int j = (int)Ranks::Two; j <= (int)Ranks::Ace; j++){

                tmpCard.rank = (Ranks)j;
                tmpCard.suit = (Suits)i;
                tmpCard.faceVal = (int)tmpCard.rank;

                card_array[cnt] = tmpCard;
                cnt++;
            }
        }
    }
};

int main(void){

    Deck deck;
    deck.initDeck();
}