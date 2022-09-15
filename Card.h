// #include<iostream>

// using namespace std;

// class Card() {
    
//     private:
//         int rank;
//         int suit;
    

//     public:
//         Card (){
//             srand(time(NULL))
//             rank = 1 + (std::rand() % (int)13)
//             suit = 1 + (std::rand() % (int)4)
//         }

//         int getRank(){
//             return rank;
//         }

//         int getSuit(){
//             return suit;
//         }

//         string rankStr(){
//             switch (rank){
//                 case 1:
//                     return "Ace";
//                     break;
//                 case 2:
//                     return "Two";
//                     break;
//                 case 3:
//                     return "Three";
//                     break;
//                 case 4:
//                     return "Four";
//                     break;
//                 case 5:
//                     return "Five";
//                     break;
//                 case 6:
//                     return "Six"
//                     break;
//                 case 7:
//                     return "Seven";
//                     break;
//                 case 8:
//                     return "Eight"
//                     break;
//                 case 9:
//                     return "Nine";
//                     break;
//                 case 10:
//                     return "Ten"
//                     break;
//                 case 11:
//                     return "Jack";
//                     break;
//                 case 12:
//                     return "Queen"
//                     break;
//                 case 13:
//                     return "King";
//                     break;
//                 case default:
//                     return "ERROR UNKNOWN RANK";
//                     break;
//             }
//         }

//         string suitStr(){
//             switch (suit){
//                 case 1:
//                     return "Spades";
//                     break;
//                 case 2:
//                     return "Clubs"
//                     break;
//                 case 3:
//                     return "Hearts";
//                     break;
//                 case 4:
//                     return "Diamonds";
//                     break;
//                 case default:
//                     return "ERROR UNKNOWN SUIT"
//                     break;
//             }
//         }
// }