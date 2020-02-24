//**********************************************************************
//					Program is written by Joshua Yang
//					Student ID is 2355145
//					Professor of course is Rene German
//					Date is 2/24/2020
//
//					Assignment objective is...
//					 
//
//
//
//
//
//**********************************************************************

#include "head1.h"
//#include "Source2.cpp" ////DONT NEED TO INCLUDE IF NO STANDARD NAMESPACE IS BEING USED IN MAIN BODY(1)

using namespace std;

int main(int argc, char* argv[])
{
	//Data Declarations
	char input1;
	bool done = false;


	do
	{
		//User's choices input 
		system("cls");
		cout << "Would you like to analyse some DNA txt files? (Y/N)" << endl;
		cin >> input1;
	
		if (input1 == 'y' || input1 == 'Y')
		{
			//Function call for txt file input
			fileDirectory();

		}
		else if (input1 == 'n' || input1 == 'N')
		{
			cout << "Program exiting, press any button..." << endl;
			done = true;
		}
		else
		{
			cout << "Invalid answer. Answer with Y for yes or N for no." << endl;
			system("pause");
		}

	} while (!done);




	
}

//References:
//system("pause");

/*
//Algorithm Setup			|			Corresponding C++ Statements
Steps to iterate :
Set up file to check if input is recieved
Pick up one string per line of the TXT file
Compute the length of the string
Compute the type of nucleotide bigram
Print the summary statistic to a txt file called(yourname.out)
Print 1000 DNA string within the Gaussian distribution.
Ask if user wants to try again
Set program to exit if NO.
*/