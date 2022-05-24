#include<iostream>
#include<string>

#define NUM_CARD_VALUES 13
#define NUM_SUITS 4
#define DECK_SIZE 52

using namespace std;

class Card{
    public:
        char faceVal;
        string suit;

        void printcard() {
            cout << faceVal << " of " << suit << endl;
        }
};

Card deck[DECK_SIZE];

int main(){

    char faceVals[NUM_CARD_VALUES] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    string suits[NUM_SUITS] = {"Spades","Clubs","Hearts","Diamonds"};

    int index = 0;
    for(int i = 0 ; i < NUM_SUITS ; i ++){
        for(int j = 0 ; j < NUM_CARD_VALUES ; j++){
            deck[index].faceVal = faceVals[j];
            deck[index].suit = suits[i];
            index++;
        }
    }
    deck[0].printcard();

}