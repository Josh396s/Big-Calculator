//**********************************************************************************
// Joshua Angel, joangel
// PA6
// Arithmetic.cpp
// Client Module for BigInteger ADT
//**********************************************************************************

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include<string>
#include"BigInteger.h"

using namespace std;

#define SIZE 2000

int main(int argc, char * argv[]) {

    //Ensure 3 arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: Arithmetic <input file> <output file>\n");
        exit(1);
    }

    //Open the input file
    ifstream in;
    in.open(argv[1], ios::in);

    //Open the output file
    ofstream out;
    out.open(argv[2], ios::trunc);

    string line;
    string first;
    string second;
    if(in.is_open()){//Read from input file
        int count = 0;
        while(getline(in, line)){//Read line by line
            if(count == 0){
                first = line;
            }
            else if (count == 2){
                second = line;
            }
            count++;
        }
    } else {
      cout << "Error: Unable to open input file";
    }

    //Make BigIntegers
    BigInteger A = BigInteger(first);
    BigInteger B = BigInteger(second);
    BigInteger three = BigInteger("3");
    BigInteger two = BigInteger("2");
    BigInteger nine = BigInteger("9");
    BigInteger sixteen = BigInteger("16");

    if(out.is_open()){//Write to output file
        //𝐴, 𝐵, 𝐴 + 𝐵, 𝐴 − 𝐵, 𝐴 − 𝐴, 3𝐴 − 2𝐵, 𝐴𝐵, 𝐴
        out << "" << A;
        out << "\n\n" << B;
        out << "\n\n" << A+B;
        out << "\n\n" << A-B;
        out << "\n\n" << A-A;
        out << "\n\n" << (three * A) - (two * B);
        out << "\n\n" << A*B;
        out << "\n\n" << A*A;
        out << "\n\n" << B*B;
        out << "\n\n" << (nine * (A*A*A*A)) + (sixteen * (B*B*B*B*B));
        out << "\n\n";
    } else {
        cout << "Error: Unable to write to output file";
    }

    //Close the files
    in.close();
    out.close();
    return(0);
}