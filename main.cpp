/*
Joseph Griffith
2016/04/27
CS 253-001
PA9

PA9 finds similar actions in a motion capture data file from an Xbox Kinect II.
	Building on assignments PA1-PA8, PA9 now compares segments of a single 
	motion capture data file and reports the starting and ending points for a 
	repeated action. It compares the first 30+n frames to the 
	closest Euclidean distance match for the coordinate points of the first 30+n
	frames to . 

*/

#include <iostream>
#include <fstream>
#include <string>
#include "Point3D.h"
#include "PoseDisplay.h"
#include <sstream>
#include <vector>
#include "Parser.h"
#include "NumberCruncher.h"
#include "Animation.h"
#include "Matrix.h"

using std::cout;
using std::cerr;

/*******************************************************************************
______________() -	descriptionOfBehavior
arguments -			descriptionOfArguments
returns -			descriptionOfReturnType
*******************************************************************************/
int main(int argc, char* argv[])	//argv[1] == name of the input file if user gave the right number of arguments
{
	Matrix outTable;

	if (argc != 2)
	{
		cerr << "error: main() - arguments not <program> <file>" << endl;
		return -1;
	}
	else
	{
		outTable.distType = 4;
	}

	Parser parseclese;

	//1st file
	if (!parseclese.openInputFile(argv[1]))
	{
		cerr << "error: main() - file 1 open failed" << endl;
		return -1;
	}
	if (!parseclese.getAnimation(outTable.file))
	{
		cerr << "error: main() - getAnimation 1 failed" << endl;
		return -1;
	}
	if (outTable.file.size() < 60)
	{
		cerr << "error: main() - file too small" << endl;
		return -1;
	}
	NumberCruncher jaws;
	if (!jaws.normalize(outTable.file))
	{
		cerr << "error: main() - normalizer 1 failed" << endl;
		return -1;
	}
	
	outTable.file.n = outTable.file.size();
	outTable.file.stop = (outTable.file.n / 2) +1;

	for (outTable.file.start = 30; outTable.file.start < outTable.file.stop; outTable.file.start++)
	{
		for (unsigned int i = 0; i < outTable.file.start; i++)
		{
			outTable.data2.push_back(outTable.file[i]);
		}
		for (unsigned int i = outTable.file.start; i < outTable.file.n; i++)
		{
			outTable.data1.push_back(outTable.file[i]);
		}

		if (!outTable.distance())
		{
			cerr << "error: main() - matrix.distance() failed" << endl;
			return -1;
		}
		//PA5
		outTable.dynamicTimeWarping(outTable.file.start);

		outTable.data1.clear();
		outTable.data2.clear();
	}

	cout << outTable.prefixLength << endl;

	return 0;
}

//PA8
/*******************************************************************************
repeatCheck() -	checks for duplicates of the action argument so it can avoid work
arguments -		argc and argv to check program arguments, and a reference to an 
					int for an index to print the duplicate 
					(??? should just print the action, wtf?)
returns -		bool for pass/fail
*******************************************************************************/
//bool repeatCheck(int argc, char *argv[], int &index)
//{
//	//argc == n
//	//	0	1	2	...	n-2		n-1
//	//			| iterate |
//	string first = { argv[1] };
//	string next;
//	//cout << "long file: " << first << endl;
//	for (int i = 2; i < argc-1; i++)
//	{
//		next = { argv[i] };
//		//cout << "next file: " << next << endl;
//		//if (argv[1] == argv[i])
//		if (first == next)
//		{
//			//dupcheck[i] = 1;
//			//cout << argv[i] << endl;
//			index = i;
//			return true;
//		}
//		else
//		{
//			//dupcheck[i] = 0;
//		}
//	}
//	return false;
//}













