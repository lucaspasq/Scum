#include<iostream>
#include<string.h>
#include<vector>
#include<cstdlib>

using namespace std;

//data types/structures
enum Ranks
{
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

enum Suits
{
    Spades,
    Clubs,
    Diamonds,
    Hearts
};

struct Card 
{
    Ranks rank;
    Suits suit;
    int faceVal;
};

struct Deck
{
    //Card card_array[52];
    vector<Card> cards;
    int deck_size = 52;
};

struct Player
{
    vector<Card> hand;
};

//Function declarations
void initDeck(Deck &deck);
void printDeck(Deck &deck);
void printCard(Card &card);
void shuffle(Deck &deck);

//Main
int main(void)
{
    Deck deck;
    initDeck(deck);
    printDeck(deck);
    shuffle(deck);
    printDeck(deck);
}


//Function Definitions
void initDeck(Deck &deck)
{
    Card tmpCard;
    int cnt = 0;

    for(int i = (int)Suits::Spades; i <= (int)Suits::Hearts; i++)
    {

        for(int j = (int)Ranks::Two; j <= (int)Ranks::Ace; j++)
        {

            tmpCard.rank = (Ranks)j;
            tmpCard.suit = (Suits)i;
            tmpCard.faceVal = (int)tmpCard.rank;
            deck.cards.push_back(tmpCard);
            
            // card_array[cnt] = tmpCard;
            // cnt++;
        }
    }
}

void printDeck(Deck &deck)
{
    for (int i = 0 ; i < deck.deck_size ; i ++)
    {
        printCard(deck.cards[i]);
    }
}

void printCard(Card &card)
{
    std::cout << card.rank << " of " << card.suit << endl;
}

void shuffle(Deck &deck)
{
    Deck tempDeck;

    while(!deck.cards.empty())
    {
        size_t randIndex = rand() % deck.cards.size();
        tempDeck.cards.push_back(deck.cards[randIndex]);
        deck.cards.erase(deck.cards.begin() + randIndex);
    }

    deck = tempDeck;
}