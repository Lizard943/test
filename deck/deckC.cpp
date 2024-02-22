#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
void c(int n){
    HANDLE hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor,n);
}
enum Suit {diamond, heart, club, spade};
class Card 
{
private:
    int value;
    Suit suit;
public:
    Card(){}
    void setValue(int v){
        value = v;
    }
    int getValue() { 
        return value; 
    }
    void setSuit(Suit st){
        assert (st == diamond || st == club || st == spade || st == heart);
        suit = st; 
    }
    Suit getSuit() { 
        return suit; 
    }
    void display(){
        c(15);
        if (value >=2 && value <= 10){
            cout << value;
        }
        else
        {
            switch(value){
                case 11: cout << "J"; break; 
                case 12: cout << "Q"; break; 
                case 13: cout << "K"; break; 
                case 14: cout << "A"; break; 
            }
        }
        switch(suit){
            case diamond:c(4); cout << char(4) << " "; break;
            case heart:c(4); cout << char(3) << " "; break;
            case club:c(9); cout << char(5) << " "; break;
            case spade:c(9); cout << char(6) << " "; break;
        }
    }
};

class Deck 
{
private:
    Card card[52];
    int topcard;
public:
    Deck(){
        topcard = 0;
        for (int i = 0; i < 52; i++){
            card[i].setValue((i%13)+2);
            switch(i/13)
            {
                case 0: card[i].setSuit(diamond); break;
                case 1: card[i].setSuit(heart); break;
                case 2: card[i].setSuit(club); break;
                case 3: card[i].setSuit(spade); break;
            }
        }
    }
    void shuffle() {
        srand(time(NULL));
        for (int i = 0; i < 52; i++){
            int j = rand() % 52;
            Card c = card[i];
            card[i] = card[j];
            card[j] = c;
        }
        topcard=0;
    }
    Card getCard(){
        return card[topcard++];
    }
};

class Hand
{
private:
    Card hand[5];
    int numcards;
public:
    Hand() {
        numcards = 0;
    }
    ~Hand() {
    }
    void draw(Deck &d) {
        hand[numcards++] = d.getCard();
    }
    void showHand(){
        for (int i=0; i<5; i++){
            hand[i].display();
        }
    }
    void sort() {
        bool swapped = false;
        do
        {
            swapped = false;
            for(int i=0; i<4; i++)
            {
                if(hand[i].getValue() > hand[i+1].getValue())
                {
                    Card c = hand[i];
                    hand[i] = hand[i+1];
                    hand[i+1] = c;
                    swapped = true;
                }
            }
        }
        while(swapped == true);
    }
    bool pairr();
    bool tpair();
    bool tri();
    bool straight();
    bool flush();
    bool four();
    bool strfl();
    bool full();
    void check();
};

