//**********************************************************************************
// Joshua Angel, joangel
// PA6
// BigInteger.cpp
// Implementation of the BigInteger ADT
//**********************************************************************************

#include<string>
#include<stdexcept>
#include <iostream>
#include <math.h>
#include"BigInteger.h"

const int power = 2;
const long base = pow(10, 2);
// Class Constructors & Destructors ----------------------------------------

// BigInteger()
// Constructor that creates a new BigInteger in the zero state:
// signum=0, digits=().
BigInteger::BigInteger(){
    signum = 0;
    List digits;
}

// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s){
    if(s.length() == 0){//If s is empty
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }
    int counter = 0;
    for(unsigned long i = 0; i < s.length(); i++) {
        if(s.at(i) == '-' ){//Negative List
            signum = -1;
            i++;
        }
        else if(s.at(i) == '+' ){//Positive List
            signum = 1;
            i++;
        }
        char a = s.at(i);
        long num = a - '0';//Convert character to long
        if(num < 0 || num > 9){//If character is not a valid number
            throw std::invalid_argument("\"BigInteger: Constructor: non-numeric string");
        }
        else{
            if(counter < base) {
                digits.insertBefore(num);
                if (counter % base == 0) {//Reset counter if digits fill base
                    counter = 0;
                }
            }
        }
        counter++;
    }
    digits.moveFront();
}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N){
    this->signum = N.signum;
    this->digits = N.digits;
}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string(){
    std::string s = "";
    if(signum == 0){//If BigInteger is 0
        s += "0";
    }
    if(signum == -1){//If BigInteger is Negative
        s += "-";
    }
    digits.moveFront();
    for(int i = 0; i < digits.length(); i++){
        s += std::to_string(digits.moveNext());
    }

    return s;
}

// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ){
    return stream << N.BigInteger::to_string();
}