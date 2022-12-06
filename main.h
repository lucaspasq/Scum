#include<iostream>
#include<vector>
#include<string.h>

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

    // inline bool operator==(const Card lhs, const Card rhs)
    // {
    //     return (lhs.rank == rhs.rank) && (lhs.suit == rhs.suit) && (lhs.faceval == rhs.faceval);
    // }
};

struct Deck
{
    vector<Card> cards;
    int deck_size = 52;
};

struct Player
{
    vector<Card> hand;
    string playerName; 
    bool aiFlag;
};

struct Scum
{
    vector<Player> players;
    Deck deck;
    Deck muck;
    Deck centerCards;
    int singleDoubleTriple = 0;
    int numPlayers;
    int handSize = deck.deck_size / numPlayers;
    int currentPlayer;
    int startingPlayer;
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
void aiHandleTurn(Scum &scum);
void playerHandleTurn(Scum &scum);
int findStartingPlayer(Scum &scum);
bool containsCard(vector<Card> &hand, Card &card);
void shedCard(Player &player, Card card, Scum &scum);
void shedRank(Ranks ranktoShed, Player &player, Scum &scum);
bool cardsEqual(Card c1, Card c2);
bool ranksEqual(Ranks r1, Ranks r2);
void checkSingleDoubleTriple(Scum &scum);
int countRankinHand(Scum &scum, Ranks rank);
void checkHouse(Scum &scum, Player &player);
void play(Scum &scum);