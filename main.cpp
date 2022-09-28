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
    string playerName;
};

struct Scum
{
    vector<Player> players;
    Deck deck;
    Deck muck;
    Deck centerCards;
    int numPlayers;
    int handSize = deck.deck_size / numPlayers;
};

//Function declarations
void initScum(Scum &scum);
void initDeck(Deck &deck);
void printDeck(Deck &deck);
void printCard(Card &card);
void shuffle(Deck &deck);
void dealHands(Scum &scum);
void printHand(vector<Card> &hand, int handSize);
void addPlayers(Scum &scum);
void showScum(Scum &scum);
void play(Scum &scum);

//Main
int main(void)
{
    Scum scum;
    play(scum);
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
    cout << (Ranks)card.rank << " of " << (Suits)card.suit << endl;
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

void dealHands(Scum &scum)
{
    for(int i = 0; i < scum.handSize; i++)
    {
        for(int j = 0 ; j < scum.numPlayers ; j++)
        {
            scum.players[j].hand.push_back(scum.deck.cards[0]);
            scum.deck.cards.erase(scum.deck.cards.begin());
        }
    }
}

void printHand(vector<Card> &hand)
{
    cout<<"size of hand: "<<hand.size()<<endl;
    for(Card card : hand)
    {
        printCard(card);
    }
}

void initScum(Scum &scum)
{
    scum.handSize = scum.deck.deck_size / scum.numPlayers;
    initDeck(scum.deck);
    shuffle(scum.deck);
    addPlayers(scum);
}

void addPlayers(Scum &scum)
{
    for(int i = 0; i < scum.numPlayers; i++)
    {
        Player tmp;
        scum.players.push_back(tmp);
    }
}

void showScum(Scum &scum)
{
    for(int i = 0 ; i < scum.numPlayers ; i++)
    {
        cout<<"Player "<<i + 1<<"'s hand:\n"<<endl;
        printHand(scum.players[i].hand);
        cout<<"\n\n";
    }

    cout<<"Current deck:\n"<<endl;
    printDeck(scum.deck);
}

void play(Scum &scum)
{
    cout<<"Welcome to Scum! How many players? "<<endl;
    cin>>scum.numPlayers;
    initScum(scum);
    cout<<"Hand sizes: "<<scum.handSize<<endl;
    dealHands(scum);
    showScum(scum);

    bool endOfGame = false;

    //Main loop
    while(!endOfGame)
    {
        int currentPlayer = 0;

        currentPlayer = 0 ? currentPlayer = scum.numPlayers - 1 : currentPlayer ++; 
        if(currentPlayer == scum.numPlayers - 1)
        {
            cout<<"END"<<endl;
            endOfGame = true;       
        }
    }
}