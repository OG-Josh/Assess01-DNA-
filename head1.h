#ifndef HEAD1_H
#define HEAD1_H

//TRY TO KEEP INCLUDE LIBRARIES IN HEADER UNLESS NEED IT DIRECTLY FOR SPECIFIC CPP FILES
//Include Guard is the main reason.
//Library Directories
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<ctime>
#include<cctype>
#include<cstdlib>
#include<fstream>

//Declare global variables and functions in header
//Function Declarations

void fileDirectory();
void printFunc(int sum, double mean, int A, int C, int T, int G, int AA, int AC, int AT, int AG, int CA, int CC, int CT, int CG, int TA, int TC, int TT, int TG, int GA, int GC, int GT, int GG, double variance, double  standardDeviation);

const int maxStrands = 1000;


class dataSet
{
private:

public:


};



#endif
