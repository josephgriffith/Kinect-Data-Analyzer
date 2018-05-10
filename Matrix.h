#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include "Animation.h"
#include "Distance.h"
#include "AvgDistance.h"
#include "MedDistance.h"
#include "LinfDistance.h"
#include "L2Distance.h"
#include <typeinfo>
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::setprecision;
using std::vector;
using std::ofstream;
using std::string;

class Matrix
{
	public:
		Matrix();
		~Matrix();

		int sort;
		int distType;
		double minDistance;
		int minFileIndex;
		int prefixLength;
		Animation file;
		Animation data1;
		Animation data2;

		vector<double> row;
		vector<vector<double>> matrix;
		vector<vector<double>> minRow;

		void printMatrix(vector<vector<double>> &output);
		void printVector(vector<double> &output);
		void dynamicTimeWarping(int index);

		bool distance();

	private:


};




#endif


