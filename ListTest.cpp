//**********************************************************************************
// Joshua Angel, joangel
// PA6
// ListTest.cpp
// A test client for List ADT
//**********************************************************************************

#include<iostream>
#include<stdexcept>
#include"List.h"

using namespace std;

int main() {

    List A;
    List B;

    for(long i = 1; i <= 10; i++){
        A.insertBefore(i);
    }
    cout << "A = " << A << endl;

    for(long i = 1; i <= 11; i++){
        B.insertBefore(i);
    }
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << endl;


   //JOIN----------------------------------------------------------------------------------------
   cout << "JOIN--------------------------------------------------------------------------" << endl;
   cout << "A + B = " << A.concat(B) << endl;


   //EQUALS----------------------------------------------------------------------------------------
   cout << "EQUALS--------------------------------------------------------------------------" << endl;
   cout << "A = B: " << A.equals(B) << endl;
   cout << endl;

   //CLEANUP----------------------------------------------------------------------------------------
   cout << "CLEAN UP--------------------------------------------------------------------------" << endl;
   A.cleanup();
   cout << "A = " << A << endl;
   cout << "Length = " << A.length() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << "Front = " << A.front() << endl;
   cout << "Back = " << A.back() << endl;
   cout << endl;


   //FIND NEXT//PREV----------------------------------------------------------------------------------------
   A.moveFront();
   cout << "FIND NEXT--------------------------------------------------------------------------" << endl;
   cout << "Find 5: " << A.findNext(5) << endl;
   cout << "Find 9: " << A.findNext(9) << endl;
   cout << "FIND PREV--------------------------------------------------------------------------" << endl;
   cout << "Find 7: " << A.findPrev(7) << endl;
   cout << "Find 3: " << A.findPrev(3) << endl;
   cout << "Find 10: " << A.findPrev(10) << endl;

   //SET AFTER/BEFORE----------------------------------------------------------------------------------------
   cout << "SET AFTER/BEFORE--------------------------------------------------------------------------" << endl;
   A.moveFront();
   A.setAfter(100);
   A.moveBack();
   A.setBefore(200);
   cout << "A = " << A << endl;
   cout << endl;

   //ERASE AFTER/BEFORE----------------------------------------------------------------------------------------
   cout << "ERASE AFTER/BEFORE--------------------------------------------------------------------------" << endl;
   A.moveFront();
   A.eraseAfter();
   A.eraseAfter();
   A.eraseAfter();
   cout << "A = " << A << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << endl;

   //MOVE NEXT----------------------------------------------------------------------------------------
   A.moveFront();
   cout << "MOVE NEXT--------------------------------------------------------------------------" << endl;
   cout << "MoveNext = " << A.moveNext() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << "MoveNext = " << A.moveNext() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << "MoveNext = " << A.moveNext() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << endl;
   //MOVE PREV----------------------------------------------------------------------------------------
   A.moveBack();
   cout << "MOVE PREV--------------------------------------------------------------------------" << endl;
   cout << "MovePrev = " << A.movePrev() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << "MovePrev = " << A.movePrev() << endl;
   cout << "Cursor = " << A.position() << endl;
   cout << "MovePrev = " << A.movePrev() << endl;
   cout << "Cursor = " << A.position() << endl;

    //CLEAR----------------------------------------------------------------------------------------
    cout << "CLEAR--------------------------------------------------------------------------" << endl;
    A.clear();
    cout << "A = " << A << endl;
    cout << "Length = " << A.length() << endl;
    cout << "Cursor = " << A.position() << endl;
   return( EXIT_SUCCESS );
}