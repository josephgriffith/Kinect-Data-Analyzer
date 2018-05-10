#include "Matrix.h"

Matrix::Matrix()
{
	sort = 0;
	minDistance = std::numeric_limits<double>::max();
	distType = -444;
	minFileIndex = -444;
}
Matrix::~Matrix()
{
}


//PA4
/*******************************************************************************
sortFiles() -	sets a flag for which data set is smaller
arguments -		reference to a Matrix holding the data sets
returns -		void
*******************************************************************************/
//void Matrix::sortFiles()
//{
//	if (data1.size() <= data2.size())
//	{
//		sort = 1;
//	}
//	else if (data2.size() < data1.size())
//	{
//		sort = 2;
//	}
//}
/*******************************************************************************
writeDistanceTable() -	writes a file from a Matrix's matrix member
arguments -				a file name to write to
returns -				true/false for succeed/fail
*******************************************************************************/
//bool Matrix::writeDistanceMatrix(const char outputFile[])
//{
//	ofstream fout;
//	fout.open(outputFile);
//	if (!fout.is_open())
//	{
//		string file = outputFile;
//		cerr << "error: writeDistanceMatrix() - unable to open output file '" << file << "', file name may not be third argument, or may not have file permission" << endl;
//		return false;
//	}
//
//	for (unsigned int i = 0; i < matrix.size(); i++)
//	{
//		for (unsigned int j = 0; j < matrix[i].size(); j++)
//		{
//			fout << fixed << setprecision(8) << matrix[i][j] << " ";
//		}
//		fout << "\n";
//	}
//	fout.close();
//
//	return true;
//}


//PA5
/*******************************************************************************
printMatrix() -	prints a 2D vector of doubles
arguments -		a reference to a 2D vector of doubles
returns -		void
*******************************************************************************/
void Matrix::printMatrix(vector<vector<double>> &output)
{
	for (unsigned int i = 0; i < output.size(); i++)
	{
		cout << "Line " << i + 1 << ": ";
		printVector(output[i]);
		cout << endl;
	}
}
/*******************************************************************************
printVector() -	prints a vector of doubles
arguments -		a reference to a vector of doubles
returns -		void
*******************************************************************************/
void Matrix::printVector(vector<double> &output)
{
	for (unsigned int j = 0; j < output.size(); j++)
	{
		cout << fixed << setprecision(8) << output[j] << " ";
	}
}
/*******************************************************************************
dynamicTimeWarping() -	finds a mapping from the frames of a short video to the 
							closest matches in the longer video >= the short 
							video's frame's index
arguments -				none
returns -				true/false for succeed/fail
*******************************************************************************/
void Matrix::dynamicTimeWarping(int index)
{
	minRow.clear();
	minRow.push_back(matrix[0]);

	if (minRow[0].size() > 0)
	{
		for (unsigned int i = 1; i < minRow[0].size(); i++)
		{
			if (minRow[0][i] > minRow[0][i - 1])
			{
				minRow[0][i] = minRow[0][i - 1];
			}
		}
	}

	double rowMin = matrix[0][0];

	if (matrix.size() > 1)
	{
		for (unsigned int i = 1; i < matrix.size(); i++)			//traverse rows
		{
			unsigned int j = 0;
			for (; j < matrix[i].size(); j++)						//traverse columns
			{
				matrix[i][j] += minRow[0][j];
				if (j == 0)											//start each row values
				{
					rowMin = matrix[i][j];
					minRow[0][j] = matrix[i][j];
				}
				else //if (i == matrixOut.size()-1)					//maybe want to not overwrite the last minRow
				{
					if (matrix[i][j] < rowMin)
					{
						rowMin = matrix[i][j];
					}
					minRow[0][j] = rowMin;
				}
			}
			minRow[0].clear();
		}
	}
	else
	{
		rowMin = minRow[0][minRow[0].size() - 1];
	}

	rowMin /= (file.start);

	if (rowMin < minDistance)
	{
		minDistance = rowMin;
		minFileIndex = index;
		prefixLength = file.start;
	}

	matrix.clear();
}


//PA6, PA7
/*******************************************************************************
distanceSelection() -	selects the method of calculating distance
arguments -			pointer to start of character array containing the 
						argument for distance type
returns -			true if valid distance type, false if not
*******************************************************************************/
//bool Matrix::distanceSelection(const char in[])
//{
//	string input = in;
//	if (input == "avg")
//	{
//		distType = 1;
//	}
//	else if (input == "med")
//	{
//		distType = 2;
//	}
//	else if (input == "Linf")
//	{
//		distType = 3;
//	}
//	else if (input == "L2")
//	{
//		distType = 4;
//	}
//	else
//	{
//		cerr << "error: distanceSelection(), matrix - " << input << " is not a valid distance type" << endl;
//		return false;
//	}
//	return true;
//}

/*******************************************************************************
distance() -	selects the right polymorphic distance behavior, then calls 
					animationDistance, populating the distance matrix
arguments -		none
returns -		bool for pass/fail
*******************************************************************************/
bool Matrix::distance()
{
	const Distance* distance;
	matrix.clear();

	switch (distType)
	{
		case 1:
			distance = new const AvgDistance();
			break;
		case 2:
			distance = new const MedDistance;
			break;
		case 3:
			distance = new const LinfDistance;
			break;
		case 4:
			distance = new const L2Distance;
			break;
		default:
			cerr << "error: distance(), matrix - distType is not a valid choice" << endl;
			return false;
	}

	data2.animationDistance(data1, matrix, distance);			//NxM, N <= M

	delete distance;
	return true;
}



