/*  This program contains source code for the Scum card game.
    All data structures and functions are included in this file.
    Written by Lucas Pasquarelli
    CS498 Capstone
    Fall 2022 Semester
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include "main.h"

using namespace std;

// //data types/structures
// enum Ranks
// {
//     Two = 2,
//     Three,
//     Four,
//     Five,
//     Six,
//     Seven,
//     Eight,
//     Nine,
//     Ten,
//     Jack,
//     Queen,
//     King,
//     Ace
// };

// enum Suits
// {
//     Spades,
//     Clubs,
//     Diamonds,
//     Hearts
// };

// struct Card 
// {
//     Ranks rank;
//     Suits suit;
//     int faceVal;

//     // inline bool operator==(const Card lhs, const Card rhs)
//     // {
//     //     return (lhs.rank == rhs.rank) && (lhs.suit == rhs.suit) && (lhs.faceval == rhs.faceval);
//     // }
// };

// struct Deck
// {
//     //Card card_array[52];
//     vector<Card> cards;
//     int deck_size = 52;
// };

// struct Player
// {
//     vector<Card> hand;
//     string playerName; 
//     bool aiFlag;
// };

// struct Scum
// {
//     vector<Player> players;
//     Deck deck;
//     Deck muck;
//     Deck centerCards;
//     int numPlayers;
//     int handSize = deck.deck_size / numPlayers;
//     int startingPlayer;
// };

// //Function declarations
// void initScum(Scum &scum);
// void initDeck(Deck &deck);
// void printDeck(Deck &deck);
// void printCard(Card &card);
// void shuffle(Deck &deck);
// void dealHands(Scum &scum);
// void printHand(vector<Card> &hand, int handSize);
// void addPlayers(Scum &scum);
// void showScum(Scum &scum);
// void aiHandleTurn(Scum &scum);
// void playerHandleTurn(Scum &scum);
// int findStartingPlayer(Scum &scum);
// bool containsCard(vector<Card> &hand, Card &card);
// void shedCard(Scum &scum, Card card);
// bool cardsEqual(Card c1, Card c2);
// void play(Scum &scum);

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
    for (int i = 0 ; i < deck.cards.size() ; i ++)
    {
        printCard(deck.cards[i]);
    }
}

void printCard(Card &card)
{
    string rankStr, suitStr;
    switch(card.rank)
    {
        case Ranks(2):
            rankStr = "Two";
            break;
        case Ranks(3):
            rankStr = "Three";
            break;
        case Ranks(4):
            rankStr = "Four";
            break;
        case Ranks(5):
            rankStr = "Five";
            break;
        case Ranks(6):
            rankStr = "Six";
            break;
        case Ranks(7):
            rankStr = "Seven";
            break;
        case Ranks(8):
            rankStr = "Eight";
            break;
        case Ranks(9):
            rankStr = "Nine";
            break;
        case Ranks(10):
            rankStr = "Ten";
            break;
        case Ranks(11):
            rankStr = "Jack";
            break;
        case Ranks(12):
            rankStr = "Queen";
            break;
        case Ranks(13):
            rankStr = "King";
            break;
        case Ranks(14):
            rankStr = "Ace";
            break;
        default:
            rankStr = "Unkown";
    }

    switch(card.suit)
    {
        case Suits(0):
            suitStr = "Spades";
            break;
        case Suits(1):
            suitStr = "Clubs";
            break;
        case Suits(2):
            suitStr = "Diamonds";
            break;
        case Suits(3):
            suitStr = "Hearts";
            break;
        default:
            suitStr = "Unkown";
    }
    cout << rankStr<< " of " << suitStr << endl;
}

void shuffle(Deck &deck)
{
    Deck tempDeck;

    while(!deck.cards.empty())
    {
        srand((unsigned int)time(NULL));
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
    scum.currentPlayer = findStartingPlayer(scum);
}

void addPlayers(Scum &scum)
{
    for(int i = 0; i < scum.numPlayers; i++)
    {
        Player tmp;
        if(i < 0)
        {
            tmp.aiFlag = 1;
        }
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

void aiHandleTurn(Scum &scum)
{
    //Check if the center cards is empty
    if(scum.centerCards.cards.empty())
    {
        
    }
    else
    {

    }
    // Check if has house

}

void playerHandleTurn(Scum &scum)
{
    //This function must interface with the gui, giving th eplayer options for what to play
    int rankToShed;
    cout<<"Select a card or card(s) to shed."<<endl; 
    cout<<"Remember, singles cant play on top of doubles, and doubles cant play on top of triples!"<<endl;

    cin>>rankToShed;

    // containsCard(scum.)
}

void shedCard(Player &player, Card card, Scum &scum)
{
    vector<Card>::iterator pos;
    int i = 0;
    //for(int i = 0 ; i <player.hand.size() ; i++)
    for(pos = player.hand.begin() ; pos < player.hand.end() ; pos++)
    {
        if(cardsEqual(player.hand[i], card))
        {
            cout<<"Erasing ";
            printCard(card);
            cout<<"\n"<<endl;
            player.hand.erase(pos);
            cout<<"Adding card to top of pile\n"<<endl;
            cout<<"Center before adding\n"<<endl;
            printDeck(scum.centerCards);
            scum.centerCards.cards.push_back(card); //add the card to the top of the pile
            cout<<"After adding the card \n"<<endl;
            printDeck(scum.centerCards);
            return;
        }
        i++;
    }
}

int findStartingPlayer(Scum &scum)
{
    cout<<"Finding starting player\n"<<endl;
    Card startingCard;
    startingCard.suit = Suits(Spades);
    startingCard.rank = Ranks(Three);
    startingCard.faceVal = (int)startingCard.rank;

    for(int i = 0 ; i < scum.players.size() ; i ++)
    {
        cout<<"Index: "<<i<<endl;
        //if(count(scum.players[i].hand.begin() , scum.players[i].hand.end() , startingCard))
        if(containsCard(scum.players[i].hand, startingCard))
        {
            cout<<"Player " << i << " starts!" << endl;
            scum.startingPlayer = i;
            printHand(scum.players[i].hand);
            shedCard(scum.players[i], startingCard, scum);
            printHand(scum.players[i].hand);
            return(i);
        }
    }
}

bool containsCard(vector<Card> &hand, Card &card)
{
    cout<<"Seeing if hand contains the starting card"<<endl;
    cout<<"HAND SIZE: "<<hand.size()<<endl;
    //for(Card c : hand)
    for(int i = 0 ; i < hand.size() ; i++)
    {
        Card c = hand[i];
        //if((c.faceVal == card.faceVal) && (c.rank == card.rank) && (c.suit == card.suit))
        if(cardsEqual(c, card))
        {
            cout<<"Card is contained in the hand"<<endl;
            return true;
        }
        else
        {
            cout<<"Card is not present"<<endl;
            continue;
        }
    }
        
    return false;
}

bool cardsEqual(Card c1, Card c2)
{
    if((c1.faceVal == c2.faceVal) && (c1.rank == c2.rank) && (c1.suit == c2.suit))
    {
        cout<<"Cards are EQUAL!!!"<<endl;
        return true;
    }
    else
    {
        cout<<"Cards are NOT EQUAL..."<<endl;
        return false;
    }
}

void setSDT(Scum &scum)
{
    // Card temp;
    size_t i = 0;
    vector<Card>::iterator pos;

    if(scum.centerCards.cards.empty())
    {
        scum.singleDoubleTriple = 0;
        return;
    }

    else
    {
        for(pos = scum.centerCards.cards.begin() ; pos < scum.centerCards.cards.end() ; pos++)
        {
            // temp = scum.centerCards.cards[i];
            if(scum.centerCards.cards[i].rank == scum.centerCards.cards[i+1].rank)
            {
                scum.singleDoubleTriple++;
                i++;
            }
            else
                break;
        }

        return;
    }
}

void checkSingleDoubleTriple(Scum &scum)
{

}

void play(Scum &scum)
{
    cout<<"Welcome to Scum! How many players? "<<endl;
    cin>>scum.numPlayers;
    initScum(scum);
    cout<<"Hand sizes: "<<scum.handSize<<endl;
    dealHands(scum);
    showScum(scum);

    cout<<"NUM PLAYERS "<<scum.numPlayers<<endl;

    bool endOfGame = false;
    // int currentPlayer = 0;
    
    // currentPlayer = findStartingPlayer(scum);

    //Main loop
    cout<<"Entering main loop"<<endl;
    while(!endOfGame)
    {
        //cout<<"We are here"<<endl;
        if(scum.currentPlayer == scum.numPlayers - 1)
        {
            scum.currentPlayer = 0;
            //cout<<"END"<<endl;
            //endOfGame = true;       
        }
        else
        {
            scum.currentPlayer++;
        }
        if (scum.players[scum.currentPlayer].aiFlag == 1)
        {
            // Computer Players turn(s)
            aiHandleTurn(scum);
        }
        else
        {
            // Real Players turn
            playerHandleTurn(scum);
        }
        //currentPlayer = 0 ? currentPlayer = scum.numPlayers - 1 : currentPlayer ++; 
        
    }
}