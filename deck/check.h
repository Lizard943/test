#include <iostream>
#include "deckC.cpp"
using namespace std;
bool Hand::pairr(){
    if(hand[0].getValue() == hand[1].getValue() || hand[1].getValue()==hand[2].getValue() || hand[2].getValue()==hand[3].getValue() || hand[3].getValue()==hand[4].getValue())
    {
        return true;
    }
    else return false;
}
bool Hand::tpair(){
    if((hand[0].getValue() == hand[1].getValue() && hand[2].getValue()==hand[3].getValue())||(hand[0].getValue() == hand[1].getValue() && hand[3].getValue()==hand[4].getValue())||(hand[1].getValue() == hand[2].getValue() && hand[3].getValue()==hand[4].getValue())){
        return true;
    }
    else return false;
}
bool Hand::tri(){
    if ((hand[0].getValue()==hand[1].getValue() && hand[1].getValue()==hand[2].getValue())||(hand[1].getValue()==hand[2].getValue() && hand[2].getValue()==hand[3].getValue())||(hand[2].getValue()==hand[3].getValue() && hand[4].getValue()==hand[3].getValue())){
        return true;
    }
    else return false;
}
bool Hand::straight(){
    if(hand[1].getValue()==hand[0].getValue()+1 && hand[2].getValue()==hand[1].getValue()+1 && hand[3].getValue()==hand[2].getValue()+1 && hand[4].getValue()==hand[3].getValue()+1)
    {
        return true;
    }
    else return false;
}
bool Hand::flush(){
    if(hand[0].getSuit() == hand[1].getSuit() && hand[1].getSuit()==hand[2].getSuit() && hand[2].getSuit()==hand[3].getSuit() && hand[3].getSuit()==hand[4].getSuit())
    {
        return true;
    }
    else return false;
}
bool Hand::full(){
    if(Hand::tpair()&&Hand::tri()){
        return true;
    }
    else return false;
}
bool Hand::four(){
    if(hand[1].getValue()==hand[2].getValue() && hand[2].getValue()==hand[3].getValue() && (hand[0].getValue()==hand[1].getValue() || hand[3].getValue()==hand[4].getValue()))
    {
        return true;
    }
    else return false;
}
bool Hand::strfl(){
    if(Hand::straight()&&Hand::flush()){
        return true;
    }
    else return false;
}
void Hand::check(){
    if (Hand::straight()){
        if (Hand::strfl()){
            cout << "You got a straight flush !!" << endl; return ;
        }
        cout << "You got a straight !!" << endl; return;
    }
    if (Hand::full()){
        cout << "You got a fullhouse !!" << endl;
    }
    if (Hand::flush()){
        cout << "You got a flush !!" << endl; return;
    }
    if (Hand::four()){
        cout << "You got a four of kind !!" << endl; return;
    }
    if (Hand::tri()){
        cout << "You got a three of kind !!" << endl; return;
    }
    if (Hand::tpair()){
        cout << "You got two pair !!" << endl; return;
    }
    if (Hand::pairr()){
        cout << "You got a pair !!" << endl; return;
    }
    cout << "You got a high card " << endl; return;
}