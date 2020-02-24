#include "head1.h"
#include <iomanip>
//Use namespace in CPP instead of header
using namespace std;


void fileDirectory()
{
	string inDirectory;
	string dnaStrands;
	
	char dnaChar;
	
	int charCount = 0;
	int lineCount = 0;
	int sum = 0;

	double mean = 0.0;

	int A = 0;
	int C = 0;
	int T = 0;
	int G = 0;

	int AA = 0;
	int AC = 0;
	int AT = 0;
	int AG = 0;

	int CA = 0;
	int CC = 0;
	int CT = 0;
	int CG = 0;

	int TA = 0;
	int TC = 0;
	int TT = 0;
	int TG = 0;

	int GA = 0;
	int GC = 0;
	int GT = 0;
	int GG = 0;
	
	//**********************************************************************

	//Setting directory with user's input
	cout << "Please enter the name of the file you want to open: " << endl;
	cin.ignore();
	getline(cin, inDirectory);

	//**********************************************************************

	//Opening File from Directory
	ifstream inFile;
	inFile.open(inDirectory);

	//**********************************************************************
	//Check if File is in directory
	if (inFile.fail())
	{
		cout << "FILE NOT FOUND! Try again!" << endl;
		return;
	}
	//**********************************************************************
	
	//Checking the length of the dna string
	char preDNAChar = ' ';
	int isBigram = 0;
	int lineLength = 0;

	while (inFile)
	{
		inFile.get(dnaChar);
		switch (dnaChar)
		{
		case 'a':
		case 'A':
			// Handle for case A
			sum++;
			A++;
			++isBigram;
			++lineLength;
			if (isBigram % 2 == 0)
			{
				switch (preDNAChar)
				{
				case 'a':
				case 'A':
					AA++;
					break;
				case 'c':
				case 'C':
					CA++;
					break;
				case 't':
				case 'T':
					TA++;
					break;
				case 'g':
				case 'G':
					GA++;
					break;
					/*case ' ':
						preDNAChar = dnaChar;*/
				default:
					break;
				}				
			}			
			preDNAChar = dnaChar;
			break;
		case 'c':
		case 'C':
			// Handle for case C
			sum++;
			C++;
			++isBigram;
			++lineLength;
			if (isBigram % 2 == 0)
			{
				switch (preDNAChar)
				{
				case 'a':
				case 'A':
					AC++;
					break;
				case 'c':
				case 'C':
					CC++;
					break;
				case 't':
				case 'T':
					TC++;
					break;
				case 'g':
				case 'G':
					GC++;
					break;
					/*case ' ':
					preDNAChar = dnaChar;*/
				default:
					break;
				}
			}
			preDNAChar = dnaChar;
			break;
		case 't':
		case 'T':
			// Handle for case T
			sum++;
			T++;
			++isBigram;
			++lineLength;
			if (isBigram % 2 == 0)
			{
				switch (preDNAChar)
				{
				case 'a':
				case 'A':
					AT++;
					break;
				case 'c':
				case 'C':
					CT++;
					break;
				case 't':
				case 'T':
					TT++;
					break;
				case 'g':
				case 'G':
					GT++;
					break;
					/*case ' ':
					preDNAChar = dnaChar;*/
				default:
					break;
				}
			}
			preDNAChar = dnaChar;
			break;
		case 'g':
		case 'G':
			// Handle for case G
			sum++;
			G++;
			++isBigram;
			++lineLength;
			if (isBigram % 2 == 0)
			{
				switch (preDNAChar)
				{
				case 'a':
				case 'A':
					AG++;
					break;
				case 'c':
				case 'C':
					CG++;
					break;
				case 't':
				case 'T':
					TG++;
					break;
				case 'g':
				case 'G':
					GG++;
					break;
					/*case ' ':
					preDNAChar = dnaChar;*/
				default:
					break;
				}
			}
			preDNAChar = dnaChar;
			break;
		case '\n':
			// Handle for new line
			if (preDNAChar != ' ')
			{
				++lineCount;
				lineLength = 0;
			}
			preDNAChar = ' ';			
			break;
		default:
			break;
		}

	}
	inFile.close();
	//cout << "DEBUG: lineCount: " << lineCount << endl;
	
	if(lineCount != 0)
		mean = (double)sum / lineCount;
	//cout << "DEBUG: mean: " << mean << endl;
	// Calculate the variance of the length
	double variance = 0.0;
	double standardDeviation = 0.0;
	double numerator = 0.0;
	inFile.open(inDirectory);
	if (!inFile.is_open())
	{
		return;
	}
	while (inFile)
	{
		string line;
		getline(inFile, line);
		//cout << "\tDEBUG: Line: " << line << ": Line size: " << line.size() << endl;
		
		if (!line.empty())
		{
			numerator += ((double)line.size() - mean) * ((double)line.size() - mean);
			//cout << "\t\tDEBUG: numerator: " << numerator << endl;
		}
	}
	inFile.close();
	variance = numerator / lineCount;
	//cout << "DEBUG: variance: " << variance << endl;
	standardDeviation = sqrt(variance);
	//cout << "DEBUG: standardDeviation: " << standardDeviation << endl;
	printFunc(sum, mean, A, C, T, G, AA, AC, AT, AG, CA, CC, CT, CG, TA, TC, TT, TG, GA, GC, GT, GG, variance, standardDeviation); //Sending data to print 
	system("pause");

	//Close input File
	//inFile.close();

}


void printFunc(int sum, double mean, int A, int C, int T, int G, int AA, int AC, int AT, int AG, int CA, int CC, int CT, int CG, int TA, int TC, int TT, int TG, int GA, int GC, int GT, int GG, double variance, double  standardDeviation)
{
	//Streaming Output File
	ofstream outFile;
	outFile.open("joshuayang.out");
	if (!outFile.is_open())
		return;

	//My data Input
	outFile << "Name: Joshua Yang" << endl;
	outFile << "Student ID: 2355145" << endl;
	outFile << "Professor Rene German" << endl;
	outFile << "Assignment 01" << endl;

	//Data Printset (Console & TXT OUT File)
	cout << "Sum of the length in the string: " << sum << endl;
	outFile << "Sum of the length in the string: " << sum << endl;
	
	cout << "The Mean of the length of the DNA strings is " << mean << endl;
	outFile << "The Mean of the length of the DNA strings is " << mean << endl;

	cout << "The variance of the length of the DNA strings is: " << variance << endl;
	outFile << "The variance of the length of the DNA strings is: " << variance << endl;

	cout << "The Standard Deviation of the length of the DNA stings is: " << standardDeviation << endl;
	outFile << "The Standard Deviation of the length of the DNA stings is: " << standardDeviation << endl;
	//relative probability of eaech nucleotide
	outFile << "Here is the relative probability of each nucleotide: " << endl << endl;
	outFile << std::setprecision(2) << "A:           " << (double)A / sum << endl;
	outFile << std::setprecision(2) << "C:           " << (double)C / sum << endl;
	outFile << std::setprecision(2) << "T:           " << (double)T / sum << endl;
	outFile << std::setprecision(2) << "G:           " << (double)G / sum << endl;

	cout << "Here is the relative probability of each nucleotide: " << endl << endl;
	cout << std::setprecision(2) << "A:           " << (double)A / sum << endl;
	cout << std::setprecision(2) << "C:           " << (double)C / sum << endl;
	cout << std::setprecision(2) << "T:           " << (double)T / sum << endl;
	cout << std::setprecision(2) << "G:           " << (double)G / sum << endl;

	//Relative probability of each nucleotide bigram
	int bigramCount = AA + AC + AT + AG + CA + CC + CT + CG + TA + TC + TT + TG + GA + GC + GT + GG;
	//int bigramCount = sum;
	outFile << endl << "Here is the relative probability of each nucleotide bigram: " << endl;
	outFile << std::setprecision(3) << "AA:          " << (double)AA / bigramCount << endl;
	outFile << std::setprecision(3) << "AC:          " << (double)AC / bigramCount << endl;
	outFile << std::setprecision(3) << "AT:          " << (double)AT / bigramCount << endl;
	outFile << std::setprecision(3) << "AG:          " << (double)AG / bigramCount << endl;

	outFile << std::setprecision(3) << "CA:          " << (double)CA / bigramCount << endl;
	outFile << std::setprecision(3) << "CC:          " << (double)CC / bigramCount << endl;
	outFile << std::setprecision(3) << "CT:          " << (double)CT / bigramCount << endl;
	outFile << std::setprecision(3) << "CG:          " << (double)CG / bigramCount << endl;

	outFile << std::setprecision(3) << "TA:          " << (double)TA / bigramCount << endl;
	outFile << std::setprecision(3) << "TC:          " << (double)TC / bigramCount << endl;
	outFile << std::setprecision(3) << "TT:          " << (double)TT / bigramCount << endl;
	outFile << std::setprecision(3) << "TG:          " << (double)TG / bigramCount << endl;

	outFile << std::setprecision(3) << "GA:          " << (double)GA / bigramCount << endl;
	outFile << std::setprecision(3) << "GC:          " << (double)GC / bigramCount << endl;
	outFile << std::setprecision(3) << "GT:          " << (double)GT / bigramCount << endl;
	outFile << std::setprecision(3) << "GG:          " << (double)GG / bigramCount << endl;


	/// Print to console
	cout << endl << "Here is the relative probability of each nucleotide bigram: " << endl;
	cout << std::setprecision(3) << "AA:          " << (double)AA / bigramCount << endl;
	cout << std::setprecision(3) << "AC:          " << (double)AC / bigramCount << endl;
	cout << std::setprecision(3) << "AT:          " << (double)AT / bigramCount << endl;
	cout << std::setprecision(3) << "AG:          " << (double)AG / bigramCount << endl;

	cout << std::setprecision(3) << "CA:          " << (double)CA / bigramCount << endl;
	cout << std::setprecision(3) << "CC:          " << (double)CC / bigramCount << endl;
	cout << std::setprecision(3) << "CT:          " << (double)CT / bigramCount << endl;
	cout << std::setprecision(3) << "CG:          " << (double)CG / bigramCount << endl;

	cout << std::setprecision(3) << "TA:          " << (double)TA / bigramCount << endl;
	cout << std::setprecision(3) << "TC:          " << (double)TC / bigramCount << endl;
	cout << std::setprecision(3) << "TT:          " << (double)TT / bigramCount << endl;
	cout << std::setprecision(3) << "TG:          " << (double)TG / bigramCount << endl;

	cout << std::setprecision(3) << "GA:          " << (double)GA / bigramCount << endl;
	cout << std::setprecision(3) << "GC:          " << (double)GC / bigramCount << endl;
	cout << std::setprecision(3) << "GT:          " << (double)GT / bigramCount << endl;
	cout << std::setprecision(3) << "GG:          " << (double)GG / bigramCount << endl;
	
	outFile.close();

	return;
}