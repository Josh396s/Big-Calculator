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

const int power = 9;
const long base = pow(10, 9);

int normalizeList(List& L, int sign);
void sumList(List& S, List A, List B, int sgn);
void scalarMultList(List& L, ListElement m);
void shiftList(List& L, int p);

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
    if(s.at(0) == '-' ){//Negative List
        signum = -1;
    } else {//Positive List
        signum = 1;
    }
    for(int i = (s.length()-1); i >= 0; i--) {//Iterate through the string
        if(s.at(i) == '-' || s.at(i) == '+'){
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

// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is positive,
// negative or 0, respectively.
int BigInteger::sign() const{
    return signum;
}

// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const{
    if(this->signum == -1 && N.signum != -1){//BigInt is less than N if it is negative, but N isn't
        return -1;
    }
    if(this->signum == 0 && N.signum == 1){//BigInt is less than N if it is 0 and N is positive
        return -1;
    }
    if(this->signum == 0 && N.signum == -1){//BigInt is greater than N if it is positive, but N isn't
        return 1;
    }
    if(this->signum == 1 && N.signum != 1){//BigInt is greater than N if it is positive, but N isn't
        return 1;
    }
    if(digits.length() > N.digits.length()){//BigInt is greater than N if it is a larger Number
        return 1;
    }
    if(digits.length() < N.digits.length()){//N is greater than BigInt if it is a larger Number
        return -1;
    }
    BigInteger A = *this;
    BigInteger B = N;

    A.digits.moveFront();
    B.digits.moveFront();
    for(int i = 0; i < A.digits.length(); i++){
        int a_val = A.digits.moveNext();
        int b_val = B.digits.moveNext();
        if(a_val < b_val){//If BigInteger is less than N
            return -1;
        }
        if(a_val > b_val){//If BigInteger is greater than N
            return 1;
        }
    }
    return 0;//BigInteger is equal to N
}

// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero(){
    digits.clear();
    signum = 0;
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of
// this BigInteger positive <--> negative.
void BigInteger::negate(){
    if(signum == 0){
        return;
    }
    if(signum == -1){//If negative, make positive
        signum = 1;
    }
    else if(signum == 1){//If positive, make negative
        signum = -1;
    }
}

// BigInteger Arithmetic operations ----------------------------------------

// add()
// Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& N) const{
    BigInteger Result;
    BigInteger A = *this;
    BigInteger B = N;
    int addition = 1;
    Result.signum = 1;
    if(A.sign() != -1 && B.sign() == -1){//A+(-B)
        addition = -1;
        B.signum = 1;
        if(A == B){//If you are subtracting the same number
            Result.makeZero();
            return Result;
        }
        else if (A < B){
            Result.signum = -1;
        }
        B.signum = -1;
    }
    if(A.sign() == -1 && B.sign() != -1){//(-A)+B
        addition = -1;
        A.signum = 1;
        if(A == B){//If you are subtracting the same number
            Result.makeZero();
            return Result;
        }
        else if (A > B){
            Result.signum = -1;
        }
        A.signum = -1;
    }
    if(A.sign() == -1 && B.sign() == -1){//If you are adding 2 negatives
        Result.signum = -1;
    }
    else if(A.sign() == -1 && A.digits.length() > B.digits.length()){//If A is negative and bigger than B
        Result.signum = -1;
        addition = -1;
    }
    else if(B.sign() == -1 && B.digits.length() > A.digits.length()){//If B is negative and bigger than A
        Result.signum = -1;
        addition = -1;
    }
    sumList(Result.digits, A.digits, B.digits, addition);
    normalizeList(Result.digits, Result.sign());
    return Result;
}

// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const{
    BigInteger Result;
    BigInteger A = *this;
    BigInteger B = N;
    if(A == B){//If you are subtracting the same number
        Result.makeZero();
        return Result;
    }
    int subtraction = -1;
    Result.signum = -1;
    if(A.sign() != -1 && B.sign() == -1){//A-(-B)
        Result.signum = 1;
        subtraction = 1;
    }
    if(A.sign() == -1 && B.sign() != -1){//-A-B
        Result.signum = -1;
        subtraction = 1;
    }
    if(A.sign() == -1 && B.sign() == -1){//(-A)-(-B)
        A.signum = 1;
        B.signum = 1;
        if(A < B){
            Result.signum = 1;
        }
        A.signum = -1;
        B.signum = -1;
    }
    if(A.sign() == 1 && B.sign() == 1){//Regular subtraction
        if(A > B){
            subtraction = -1;
            Result.signum = 1;
        }
    }
    sumList(Result.digits, A.digits, B.digits, subtraction);
    if(Result.digits.length() == 1){//Checking to see if the result is 0
        Result.digits.moveBack();
        if(Result.digits.peekPrev() == 0){
            Result.makeZero();
            return Result;
        }
    }
    normalizeList(Result.digits, Result.sign());
    return Result;
}

// mult()
// Returns a BigInteger representing the product of this and N.
BigInteger BigInteger::mult(const BigInteger& N) const{
    BigInteger Result;
    BigInteger A = *this;
    BigInteger B = N;
    if(A.digits.length() == 1){//Checking to see if A is 0
        A.digits.moveBack();
        if(A.digits.peekPrev() == 0){
            Result.makeZero();
            return Result;
        }
    }
    if(B.digits.length() == 1){//Checking to see if B is 0
        B.digits.moveBack();
        if(B.digits.peekPrev() == 0){
            Result.makeZero();
            return Result;
        }
    }
    B.digits.moveBack();
    int shifter = 0;
    for(int i = 0; i < B.digits.length(); i++){
        BigInteger Mul = A;
        long val = B.digits.movePrev();
        scalarMultList(Mul.digits, val);
        shiftList(Mul.digits, shifter);
        Result += Mul;
        //normalizeList(Result.digits, Result.sign());
        shifter++;
    }
    if(A.signum == -1 && B.signum == -1){//(-)*(-) = +
        Result.signum = 1;
    }
    else if(A.signum == -1 && B.signum == 1){//(-)*(+) = -
        Result.signum = -1;
    }
    else if(A.signum == 1 && B.signum == -1){//(+)*(-) = -
        Result.signum = -1;
    }
    return Result;
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

//Helper Functions -----------------------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L){
    L.moveBack();
    for(int i = 0; i < L.length(); i++){
        long val = L.movePrev();
        val *= -1;
        L.eraseAfter();
        L.insertAfter(val);
    }
}

// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void sumList(List& S, List A, List B, int sgn){
    A.moveBack();
    B.moveBack();
    int count = 0;
    if(A.length() == 1){//If A is zero
        if(A.peekPrev() == 0){
            S = B;
            return;
        }
    }
    if(B.length() == 1){//If B is zero
        if(B.peekPrev() == 0){
            S = A;
            return;
        }
    }
    if(A.length() <= B.length()){//Iterate through smaller number
        for(int i = 0; i < A.length(); i++){
            long a_val = A.movePrev();
            long b_val = B.movePrev();
            long tot = a_val + (sgn * b_val);
            S.insertAfter(tot);
            count++;
        }
        for(int j = 0; j < (B.length()-count); j++){//Finish adding the rest of the list
            long val = B.movePrev();
            S.insertAfter(val);
        }
    } else {
        for(int i = 0; i < B.length(); i++){
            long a_val = A.movePrev();
            long b_val = B.movePrev();
            long tot = a_val + (sgn * b_val);
            S.insertAfter(tot);
            count++;
        }
        for(int j = 0; j < (A.length()-count); j++){//Finish adding the rest of the list
            long val = A.movePrev();
            S.insertAfter(val);
        }
    }
}

// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().
int normalizeList(List& L, int sign){
    L.moveFront();
    while(L.peekNext() == 0){
        L.eraseAfter();
    }
    if(L.peekNext() < 0){//If the first digit is negative
        negateList(L);
        int sign1 = -1;
        normalizeList(L, sign1);
    }
    L.moveBack();
    std::string s = "";
    for(int i = 0; i < L.length(); i++){
        long val = L.movePrev();
        s += std::to_string(val) + "";
        int len = std::to_string(val).length();
        if(val < 0){//If the number is negative
            //Update the current Number
            long res = val + base;
            L.eraseAfter();
            L.insertAfter(res);
            //Borrow from previous number
            long update = L.peekPrev();
            update-=1;
            L.eraseBefore();
            L.insertBefore(update);
            continue;
        }
        if(len > power) {//If the current index is bigger than the power
            std::string over = "";
            int ind = len - power;
            for(int j = 0; j < ind; j++){//Get and remove the overflow
                char num = s.at(0);
                over.insert(j, 1, num);
                s.erase(s.begin());
            }
            if((i+1) == L.length()){//If you are at the front of the List
                //Add overflow to Previous Number
                long total = stol(over);
                L.insertBefore(total);
                //Update current Number
                L.eraseAfter();
                L.insertAfter(stol(s));
                //Clear Strings
                over.clear();
            } else {
                //Add overflow to Previous Number
                long previous = L.peekPrev();
                long total = previous + stol(over);
                L.eraseBefore();
                L.insertBefore(total);
                //Update current Number
                L.eraseAfter();
                L.insertAfter(stol(s));
                //Clear Strings
                over.clear();
            }
        }
        s.clear();
    }
    return sign;
}

// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult().
void shiftList(List& L, int p){
    if(p == 0){//No shift
        return;
    }
    L.moveBack();
    for(int i = 0; i < p; i++){
        L.insertAfter(0);
    }
}

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
void scalarMultList(List& L, ListElement m){
    L.moveBack();
    for(int i = 0; i < L.length(); i++){
        long val = L.movePrev();
        long result = val * m;
        L.eraseAfter();
        L.insertAfter(result);
    }
}

// Overridden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ){
    return stream << N.BigInteger::to_string();
}

// operator==()
// Returns true if and only if A equals B.
bool operator==( const BigInteger& A, const BigInteger& B ){
    if(A.BigInteger::compare(B) == 0){
        return true;
    } else{
        return false;
    }
}

// operator<()
// Returns true if and only if A is less than B.
bool operator<( const BigInteger& A, const BigInteger& B ){
    if(A.BigInteger::compare(B) == -1){
        return true;
    } else{
        return false;
    }
}

// operator<=()
// Returns true if and only if A is less than or equal to B.
bool operator<=( const BigInteger& A, const BigInteger& B ){
    if(A.BigInteger::compare(B) == 0 || A.BigInteger::compare(B) == -1){
        return true;
    } else{
        return false;
    }
}

// operator>()
// Returns true if and only if A is greater than B.
bool operator>( const BigInteger& A, const BigInteger& B ){
    if(A.BigInteger::compare(B) == 1){
        return true;
    } else{
        return false;
    }
}

// operator>=()
// Returns true if and only if A is greater than or equal to B.
bool operator>=( const BigInteger& A, const BigInteger& B ){
    if(A.BigInteger::compare(B) == 0 || A.BigInteger::compare(B) == 1){
        return true;
    } else{
        return false;
    }
}

// operator+()
// Returns the sum A+B.
BigInteger operator+( const BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.add(temp2);
    return temp3;
}

// operator+=()
// Overwrites A with the sum A+B.
BigInteger operator+=( BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.add(temp2);
    std::swap(A.digits, temp3.digits);
    std::swap(A.signum, temp3.signum);
    return A;
}

// operator-()
// Returns the difference A-B.
BigInteger operator-( const BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.sub(temp2);
    return temp3;
}

// operator-=()
// Overwrites A with the difference A-B.
BigInteger operator-=( BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.sub(temp2);
    std::swap(A.digits, temp3.digits);
    std::swap(A.signum, temp3.signum);
    return A;
}

// operator*()
// Returns the product A*B.
BigInteger operator*( const BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.mult(temp2);
    return temp3;
}

// operator*=()
// Overwrites A with the product A*B.
BigInteger operator*=( BigInteger& A, const BigInteger& B ){
    BigInteger temp = A;
    BigInteger temp2 = B;
    BigInteger temp3 = temp.mult(temp2);
    std::swap(A.digits, temp3.digits);
    std::swap(A.signum, temp3.signum);
    return A;
}
