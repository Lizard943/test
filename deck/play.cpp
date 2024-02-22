#include <iostream>
#include "check.h"

//Luanvu
int main() 
{
    test:
    system("cls");
    Deck deck;
    Hand p1;
    deck.shuffle();
    for (int i=0; i<5;i++){
        p1.draw(deck);
    }
    p1.showHand();
    p1.sort();
    cout << "\n";
    c(15);
    p1.check();
    cout << "\n";

    for (int i=0; i<5; i++){
        cout << i;
    }
    cout << endl;
    system("pause");
    goto test;
}
