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
#include <cstring>
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
    std::string b;
    for(int i = (s.length()-1); i >= 0; i--) {//Iterate through the string
        if(s.at(i) == '-' ){//Negative List
            signum = -1;
            continue;
        }
        else if(s.at(i) == '+' ){//Positive List
            signum = 1;
            continue;
        }
        char a = s.at(i);
        long num = a - '0';//Convert character to long
        if(num < 0 || num > 9){//If character is not a valid number
            throw std::invalid_argument("\"BigInteger: Constructor: non-numeric string");
        }
        b.insert(0, 1, a);
        if(b.length() == power){//Divide into proper number of digits
            digits.insertAfter(stol(b));
            b.clear();//Empty the string
        }
    }
    if(b.length() != 0){//Add any leftover digits
        digits.insertAfter(stol(b));
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
    digits.moveFront();
    if(signum == 0){//If BigInteger is 0
        s += "0";
        return s;
    }
    if(signum == -1){//If BigInteger is Negative
        s += "-";
    }
    for(int i = 0; i < digits.length(); i++){
        int val =  digits.moveNext();
        if(i == 0){
            s += std::to_string(val) + "";
        } else {
            if (std::to_string(val).length() < power) {
                int zer = power - std::to_string(val).length();
                s += std::string(zer, '0') + "" + std::to_string(val) + "";
            }
            else{
                s += std::to_string(val) + "";
            }
        }
    }
    return s;
}

// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ){
    return stream << N.BigInteger::to_string();
}