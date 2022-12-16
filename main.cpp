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
#include<unistd.h>
#include "main.h"

using namespace std;

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

bool compareRank(Card &c1 , Card &c2)
{
    return c1.rank > c2.rank;
}

void sortHands(Scum &scum)
{
    for(int i = 0 ; i < scum.numPlayers ; i ++)
    {
        sort(scum.players[i].hand.begin(), scum.players[i].hand.end(), compareRank);
        //cout<<"SORTED HAND"<<endl;
        //showScum(scum);
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
        sleep(1);
    }

    //cout<<"Current deck:\n"<<endl;
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

    bool activeTurn = true;

    while(activeTurn)
    {
        // string strRanktoShed;
        int intRankToShed;
        cout<<"\nSelect a card or card(s) to shed."<<endl; 
        cout<<"Remember, singles cant play on top of doubles, and doubles cant play on top of triples!"<<endl;
        cout<<"Playing a 2 will clear the center and play any card(s)."<<endl;
        cout<<"Enter 0 to pass your turn!"<<endl;

        cin>>intRankToShed;

        if(intRankToShed == 0)
        {
            if(scum.centerCards.cards.empty())
            {
                cout<<"You cannot pass when the center is empty!"<<endl;
                continue;
            }
            
            cout<<"Passing player "<<scum.currentPlayer<<"'s turn."<<endl;
            activeTurn = false;
            continue;
        }

        Ranks ranktoShed = Ranks(intRankToShed);
        int numRankinHand = countRankinHand(scum, (int)ranktoShed);
        if(numRankinHand == 0)
        {
            cout<<"\nYou don't have any of that rank in your hand! Try again."<<endl;
            continue;
        }
        //cout<<"NUM RANK IN HAND: "<<numRankinHand<<endl;
        //cout<<"RANK TO SHED "<<(int)ranktoShed<<endl;

        if(scum.centerCards.cards.empty())
        {
            if(ranktoShed == Ranks::Two)
            {
                cout<<"You cannot play a 2 over an empty center!"<<endl;
                continue;
            }
            else
            {
                // int numCardstoShed = countRankinHand(scum, ranktoShed);
                for(int i = 0; i < numRankinHand ; i++)
                {
                    shedRank(ranktoShed, scum.players[scum.currentPlayer-1], scum);
                }
                setSDT(scum);
                //cout<<"SDT SET TO "<<scum.singleDoubleTriple<<endl;

                //Turn is over
                activeTurn = false;
            }
        }
        else
        {
            if(ranktoShed == Ranks::Two)
            {
                numRankinHand = 1;
                shedRank(ranktoShed, scum.players[scum.currentPlayer-1], scum);
                scum.centerCards.cards.clear();
                scum.singleDoubleTriple = 0;
                cout<<"Clearing the center..."<<endl;
                //cout<<"SDT = "<<scum.singleDoubleTriple<<endl;
                printDeck(scum.centerCards);
                continue;
            }
            else if(ranktoShed == scum.centerCards.cards.back().rank)
            {
                if(numRankinHand >= 1 && scum.singleDoubleTriple == 1)
                {
                    scum.skipFlag = true;
                    //cout<<"SKIPPING SET TO TRUE"<<endl;
                    shedRank(ranktoShed, scum.players[scum.currentPlayer-1], scum);
                    activeTurn = false;
                }
            }
            else if(ranktoShed > scum.centerCards.cards.back().rank)
            {
                if(numRankinHand >= scum.singleDoubleTriple)
                {
                    for(int i = 0; i < numRankinHand ; i ++)
                    {
                        shedRank(ranktoShed, scum.players[scum.currentPlayer-1], scum);
                    }
                    activeTurn = false;
                }

                else  
                { 
                    cout<<"Not enough of that rank in your hand."<<endl; 
                    continue;
                }
            }
            else
            {
                cout<<"Cannot play a rank lower that what is on top of the center cards!"<<endl;
                continue;
            }
        }
    }
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
            scum.centerCards.cards.push_back(card); //add the card to the top of the pile
            printDeck(scum.centerCards);
            return;
        }
        i++;
    }
}

void shedRank(Ranks ranktoShed, Player &player, Scum &scum)
{
    vector<Card>::iterator pos;
    int i = 0;
    int numCardsShedded = 0;

    // Shed all of the rank in the hand if the center is empty
    if(scum.centerCards.cards.empty())
    {
        scum.singleDoubleTriple = countRankinHand(scum, ranktoShed);
        //cout<<"SDT SET TO "<<scum.singleDoubleTriple<<endl;

        for(pos = player.hand.begin(); pos != player.hand.end() ; pos++)
        {
            if(ranksEqual(player.hand[i].rank, ranktoShed))
            {
                Card tmp = player.hand[i];
                player.hand.erase(pos);
                scum.centerCards.cards.push_back(tmp);
                numCardsShedded++;

                //cout<<"SHEDDING A "<<player.hand[i].rank<<endl;
                return;
            }

            i++;
        }
    }
    
    //if center is not empty, shed SDT amount of cards
    else
    {
        for(pos = player.hand.begin(); pos != player.hand.end() ; pos++)
        {
            if(ranksEqual(player.hand[i].rank, ranktoShed))
            {
                Card tmp = player.hand[i];
                player.hand.erase(pos);
                scum.centerCards.cards.push_back(tmp);
                numCardsShedded++;

                //cout<<"SHEDDED "<<numCardsShedded<<" "<<ranktoShed<<"'S"<<endl;
                if(ranktoShed == Ranks::Two)
                {
                    if(numCardsShedded == 1)
                    {
                        //cout<<"DONE SHEDDING A 2"<<endl;
                        return;
                    }
                }
                else if(numCardsShedded == scum.singleDoubleTriple)
                {
                    //cout<<"DONE SHEDDING "<<numCardsShedded<<" CARDS"<<endl;
                    return;
                }            
            }

            i++;
        }
    }
}

int findStartingPlayer(Scum &scum)
{
    cout<<"Finding starting player\n"<<endl;
    sleep(1);
    Card startingCard;
    startingCard.suit = Suits(Spades);
    startingCard.rank = Ranks(Three);
    startingCard.faceVal = (int)startingCard.rank;

    for(int i = 0 ; i < scum.players.size() ; i ++)
    {
        if(containsCard(scum.players[i].hand, startingCard))
        {
            cout<<"Player " << i+1 << " starts!" << endl;
            // scum.startingPlayer = i+1;
            // printHand(scum.players[i].hand);
            shedCard(scum.players[i], startingCard, scum);
            scum.singleDoubleTriple = 1;
            // printHand(scum.players[i].hand);
            return(i+1);
        }
    }
    return 0;
}

bool containsCard(vector<Card> &hand, Card &card)
{
    for(int i = 0 ; i < hand.size() ; i++)
    {
        Card c = hand[i];

        if(cardsEqual(c, card))
        {
            //cout<<"Card is contained in the hand"<<endl;
            return true;
        }
        else
        {
            //cout<<"Card is not present"<<endl;
            continue;
        }
    }
        
    return false;
}

bool cardsEqual(Card c1, Card c2)
{
    if((c1.faceVal == c2.faceVal) && (c1.rank == c2.rank) && (c1.suit == c2.suit))
    {
        //cout<<"Cards are EQUAL!!!"<<endl;
        return true;
    }
    else
    {
        //cout<<"Cards are NOT EQUAL..."<<endl;
        return false;
    }
}

bool ranksEqual(Ranks r1, Ranks r2)
{
    if(r1 == r2)
        return true;

    else
        return false;
}

void setSDT(Scum &scum)
{
    // Card temp;
    //size_t i = 0;
    //vector<Card>::iterator pos;

    if(scum.centerCards.cards.empty())
    {
        scum.singleDoubleTriple = 0;
        return;
    }

    else
    {
        scum.singleDoubleTriple = 1;
        //for(pos = scum.centerCards.cards.begin() ; pos < scum.centerCards.cards.end() ; pos++)
        for(int i = 0 ; i < scum.centerCards.cards.size() ; i++)
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

        //cout<<"IN setSDT, SDT SET TO "<<scum.singleDoubleTriple<<endl;
        return;
    }
}

// Function to check if player has enough of a rank to play on top of the center
// void checkSDT(Scum &scum, Ranks rank)
// {
//     if(countRankinHand(scum, scum.centerCards.cards.back().rank) >= scum.singleDoubleTriple)
//     {

//     }
// }

int countRankinHand(Scum &scum, int ranktoShed)
{
    int numCards = 0;
    //for(vector<Card>::iterator c = scum.players[scum.currentPlayer].hand.begin() ; c < scum.players[scum.currentPlayer].hand.end() ; c++)
    for(size_t i = 0 ; i < scum.players[scum.currentPlayer-1].hand.size() ; i++)
    {
        if(scum.players[scum.currentPlayer-1].hand[i].rank == Ranks(ranktoShed))
        {
            numCards++;
        }
        //cout<<*c<<endl;
        // Card card = *c;
        // if(card.rank == (Rank)ranktoShed)
        // {
        //     numCards++;
        // }
    }
    return numCards;
}

void checkHouse(Scum &scum, Player &player)
{
    int houseRank = int(scum.centerCards.cards.back().rank);
    //cout<<"HOUSE RANK = "<<houseRank<<endl;
    int totalinCenter = 0;
    int houseRankinHand = countRankinHand(scum, houseRank);
    for(int i = 0 ; i < scum.centerCards.cards.size() ; i++)
    {
        if(scum.centerCards.cards[i].rank == houseRank)
        {
            totalinCenter++;
        }
    }
    int result = houseRankinHand + totalinCenter;
    bool responded = false;

    if(result == 4)
    {  
        // int housePlayer = scum.currentPlayer + 1;
        // if(housePlayer = scum.numPlayers + 1)
        // {
        //     housePlayer = 1;
        // } 
        cout<<"Player "<<scum.currentPlayer<<"Can call house! Enter Y/N:"<<endl;
        string inputStr;
        cin>>inputStr;
    
        while(!responded)
        {
            if(inputStr == "y" || inputStr == "Y")
            {
                responded = true;
                scum.skipFlag = false;
                scum.houseFlag = true;
                for(int i = 0; i < houseRankinHand ; i++)
                {
                    shedRank(Ranks(houseRank), player, scum);
                }
                scum.centerCards.cards.clear();
                scum.singleDoubleTriple = 0;
                return;
            }
            else if (inputStr == "n" || inputStr == "N")
            {
                responded = true;
                cout<<"Continuing on..."<<endl;
                return;
            }
            else
                cout<<"Invalid input, try again."<<endl;
        }
    }
}

void play(Scum &scum)
{
    cout<<"Welcome to Scum! How many players? "<<endl;
    cin>>scum.numPlayers;
    initScum(scum);
    dealHands(scum);
    sortHands(scum);
    scum.currentPlayer = findStartingPlayer(scum);
    sleep(1);
    showScum(scum);

    bool endOfGame = false;
    // int currentPlayer = 0;
    
    // currentPlayer = findStartingPlayer(scum);

    //Main loop
    //cout<<"Entering main loop"<<endl;
    while(!endOfGame)
    {
        //cout<<"We are here"<<endl;
        
        cout<<"Center Cards:"<<endl;
        printDeck(scum.centerCards);
        cout<<"------------------------------------------------------------------------------------"<<endl;
        //setSDT(scum);
        //cout<<"SDT: "<<scum.singleDoubleTriple<<endl;
        cout<<"\nIT IS PLAYER "<<scum.currentPlayer<<"'S TURN\n"<<endl;
        cout<<"CURRENT HAND\n"<<endl;
        printHand(scum.players[scum.currentPlayer-1].hand);
        cout<<"\nCENTER CARDS:"<<endl;
        printDeck(scum.centerCards);
        if(scum.players[scum.currentPlayer-1].aiFlag == 1)
        {
            // Computer Players turn(s)
            aiHandleTurn(scum);
            sleep(1);
        }
        else
        {
            // Real Players turn
            playerHandleTurn(scum);
            sleep(1);
        }

        //check for empty hand after the turn
        if(scum.players[scum.currentPlayer].hand.empty())
        {
            cout<<"Player "<<scum.currentPlayer<<" wins!!!"<<endl;
            endOfGame = true;
            continue;
        }
        //cout<<"TURN HANDLED, CHECKING HOUSES NOW"<<endl;

        //save the current player left off on
        int temp = scum.currentPlayer;

        //After turn is over, check for house calls
        for(int i = 1 ; i <= scum.numPlayers ; i++)
        {
            scum.currentPlayer = (i + scum.currentPlayer) % scum.numPlayers;
            if(scum.currentPlayer == 0)
            {
                scum.currentPlayer = scum.numPlayers;
            }
            else if(scum.currentPlayer == temp)
            {
                continue;
            }
            
            //cout<<"HOUSE CHECK, PLAYER "<<scum.currentPlayer<<endl;

            checkHouse(scum, scum.players[scum.currentPlayer-1]);
            if(scum.houseFlag)
            {
                scum.houseFlag = false;
                break;
            }
            sleep(1);

            //check for empty hand after house calls
            if(scum.players[scum.currentPlayer-1].hand.empty())
            {
                endOfGame = true;
                cout<<"Player "<<scum.currentPlayer<<"wins!!!";
            }
            if(!scum.houseFlag)
            {
                scum.currentPlayer = temp;
            }
            scum.houseFlag = false;
        }
    
        scum.currentPlayer++;
        if(scum.currentPlayer == scum.numPlayers + 1)
        {
            scum.currentPlayer = 1;
        }
        if(scum.skipFlag)
        {
            cout<<"Skipping player "<<scum.currentPlayer<<"!"<<endl;
            scum.currentPlayer++;
            scum.skipFlag = false;
        }
        if(scum.currentPlayer == scum.numPlayers + 1)
        {
            scum.currentPlayer = 1;
        }

        //currentPlayer = 0 ? currentPlayer = scum.numPlayers - 1 : currentPlayer ++; 
        
    }
}