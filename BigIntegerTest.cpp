//**********************************************************************************
// Joshua Angel, joangel
// PA6
// BigIntegerTest.cpp
// A test for the BigInteger ADT
//**********************************************************************************
#include<iostream>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){

    string s1 = "-123456789";
    string s2 = "987654321";
    string s3 = "9128734667000004389234563456345619187236478";
    string s4 = "-330293847502398475";

    BigInteger A = BigInteger(s1);
    BigInteger B = BigInteger(s2);
    BigInteger C = BigInteger(s3);
    BigInteger D = BigInteger(s4);


    //MULTIPLICATION--------------------------------------------------------------------------------------------
    BigInteger AtimesA = A.mult(A);
    BigInteger AtimesB = A.mult(B);
    BigInteger AtimesC = A.mult(C);
    BigInteger AtimesD = A.mult(D);
    BigInteger BtimesA = B.mult(A);
    BigInteger BtimesB = B.mult(B);
    BigInteger BtimesC = B.mult(C);
    BigInteger BtimesD = B.mult(D);
    BigInteger CtimesA = C.mult(A);
    BigInteger CtimesB = C.mult(B);
    BigInteger CtimesC = C.mult(C);
    BigInteger CtimesD = C.mult(D);
    BigInteger DtimesA = D.mult(A);
    BigInteger DtimesB = D.mult(B);
    BigInteger DtimesC = D.mult(C);
    BigInteger DtimesD = D.mult(D);

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "A * A: " << AtimesA << endl;
    cout << "A * B: " << AtimesB << endl;
    cout << "A * C: " << AtimesC << endl;
    cout << "A * D: " << AtimesD << endl;
    cout << "B * A: " << BtimesA << endl;
    cout << "B * B: " << BtimesB << endl;
    cout << "B * C: " << BtimesC << endl;
    cout << "B * D: " << BtimesD << endl;
    cout << "C * A: " << CtimesA << endl;
    cout << "C * B: " << CtimesB << endl;
    cout << "C * C: " << CtimesC << endl;
    cout << "C * D: " << CtimesD << endl;
    cout << "D * A: " << DtimesA << endl;
    cout << "D * B: " << DtimesB << endl;
    cout << "D * C: " << DtimesC << endl;
    cout << "D * D: " << DtimesD << endl;

    //SUBTRACTION--------------------------------------------------------------------------------------------
    BigInteger AminusA = A.sub(A);
    BigInteger AminusB = A.sub(B);
    BigInteger AminusC = A.sub(C);
    BigInteger AminusD = A.sub(D);
    BigInteger BminusA = B.sub(A);
    BigInteger BminusB = B.sub(B);
    BigInteger BminusC = B.sub(C);
    BigInteger BminusD = B.sub(D);
    BigInteger CminusA = C.sub(A);
    BigInteger CminusB = C.sub(B);
    BigInteger CminusC = C.sub(C);
    BigInteger CminusD = C.sub(D);
    BigInteger DminusA = D.sub(A);
    BigInteger DminusB = D.sub(B);
    BigInteger DminusC = D.sub(C);
    BigInteger DminusD = D.sub(D);

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "A - A: " << AminusA << endl;
    cout << "A - B: " << AminusB << endl;
    cout << "A - C: " << AminusC << endl;
    cout << "A - D: " << AminusD << endl;
    cout << "B - A: " << BminusA << endl;
    cout << "B - B: " << BminusB << endl;
    cout << "B - C: " << BminusC << endl;
    cout << "B - D: " << BminusD << endl;
    cout << "C - A: " << CminusA << endl;
    cout << "C - B: " << CminusB << endl;
    cout << "C - C: " << CminusC << endl;
    cout << "C - D: " << CminusD << endl;
    cout << "D - A: " << DminusA << endl;
    cout << "D - B: " << DminusB << endl;
    cout << "D - C: " << DminusC << endl;
    cout << "D - D: " << DminusD << endl;

    //ADDITION--------------------------------------------------------------------------------------------
    BigInteger AplusA = A.add(A);
    BigInteger AplusB = A.add(B);
    BigInteger AplusC = A.add(C);
    BigInteger AplusD = A.add(D);
    BigInteger BplusA = B.add(A);
    BigInteger BplusB = B.add(B);
    BigInteger BplusC = B.add(C);
    BigInteger BplusD = B.add(D);
    BigInteger CplusA = C.add(A);
    BigInteger CplusB = C.add(B);
    BigInteger CplusC = C.add(C);
    BigInteger CplusD = C.add(D);
    BigInteger DplusA = D.add(A);
    BigInteger DplusB = D.add(B);
    BigInteger DplusC = D.add(C);
    BigInteger DplusD = D.add(D);

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "A + A: " << AplusA << endl;
    cout << "A + B: " << AplusB << endl;
    cout << "A + C: " << AplusC << endl;
    cout << "A + D: " << AplusD << endl;
    cout << "B + A: " << BplusA << endl;
    cout << "B + B: " << BplusB << endl;
    cout << "B + C: " << BplusC << endl;
    cout << "B + D: " << BplusD << endl;
    cout << "C + A: " << CplusA << endl;
    cout << "C + B: " << CplusB << endl;
    cout << "C + C: " << CplusC << endl;
    cout << "C + D: " << CplusD << endl;
    cout << "D + A: " << DplusA << endl;
    cout << "D + B: " << DplusB << endl;
    cout << "D + C: " << DplusC << endl;
    cout << "D + D: " << DplusD << endl;

    //(==, <, <=, >, >=, +, +=, -, -=, *, *=)--------------------------------------------------------------------------------------------
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "A == A: " << (A==A) << endl;
    cout << "A == B: " << (A==B) << endl;
    cout << "B == B: " << (B==B) << endl;
    cout << "" << endl;
    cout << "A < A: " << (A<A) << endl;
    cout << "A < B: " << (A<B) << endl;
    cout << "B < A: " << (B<A) << endl;
    cout << "B < B: " << (B<B) << endl;
    cout << "A <= A: " << (A<=A) << endl;
    cout << "A <= B: " << (A<=B) << endl;
    cout << "B <= A: " << (B<=A) << endl;
    cout << "B <= B: " << (B<=B) << endl;
    cout << "" << endl;
    cout << "A > A: " << (A>A) << endl;
    cout << "A > B: " << (A>B) << endl;
    cout << "B > A: " << (B>A) << endl;
    cout << "B > B: " << (B>B) << endl;
    cout << "A >= A: " << (A>=A) << endl;
    cout << "A >= B: " << (A>=B) << endl;
    cout << "B >= A: " << (B>=A) << endl;
    cout << "B >= B: " << (B>=B) << endl;
    cout << "" << endl;
    cout << "A + A: " << (A+A) << endl;
    cout << "A + B: " << (A+B) << endl;
    cout << "B + A: " << (B+A) << endl;
    cout << "B + B: " << (B+B) << endl;
    cout << "A += A: " << (A+=A) << endl;
    cout << "A += B: " << (A+=B) << endl;
    cout << "B += A: " << (B+=A) << endl;
    cout << "B += B: " << (B+=B) << endl;
    cout << "" << endl;
    cout << "A - A: " << (A-A) << endl;
    cout << "A - B: " << (A-B) << endl;
    cout << "B - A: " << (B-A) << endl;
    cout << "B - B: " << (B-B) << endl;
    cout << "A -= A: " << (A-=A) << endl;
    cout << "A -= B: " << (A-=B) << endl;
    cout << "B -= A: " << (B-=A) << endl;
    cout << "B -= B: " << (B-=B) << endl;
    cout << "" << endl;
    cout << "A * A: " << (A*A) << endl;
    cout << "A * B: " << (A*B) << endl;
    cout << "B * A: " << (B*A) << endl;
    cout << "B * B: " << (B*B) << endl;
    cout << "A *= A: " << (A*=A) << endl;
    cout << "A *= B: " << (A*=B) << endl;
    cout << "B *= A: " << (B*=A) << endl;
    cout << "B *= B: " << (B*=B) << endl;
    //NEGATE--------------------------------------------------------------------------------------------
    cout << "" << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    A.negate();
    B.negate();
    cout << "A Negate: " << A << endl;
    cout << "B Negate: " << B << endl;

    //SIGN--------------------------------------------------------------------------------------------
    cout << "" << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;

    cout << "A: " << A.sign() << endl;
    cout << "B: " << B.sign() << endl;
    cout << "A: " << A.sign() << endl;

    //COMPARE--------------------------------------------------------------------------------------------
    cout << "" << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;

    cout << "A:B " << A.compare(B) << endl;
    cout << "B:A " << B.compare(A) << endl;
    cout << "A:A " << A.compare(A) << endl;
    cout << "A:C " << A.compare(C) << endl;
    cout << "C:A " << C.compare(A) << endl;
    cout << "B:C " << B.compare(C) << endl;
    cout << "C:B " << C.compare(B) << endl;
    cout << "C:C " << C.compare(C) << endl;

    //MAKE ZERO--------------------------------------------------------------------------------------------
    cout << "" << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    A.makeZero();
    B.makeZero();
    cout << "A Zero: " << A << endl;
    cout << "B Zero: " << B << endl;

    return EXIT_SUCCESS;
}