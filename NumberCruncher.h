#ifndef NUMBER_CRUNCHER_H
#define NUMBER_CRUNCHER_H

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Point3D.h"
#include "Animation.h"
#include "Matrix.h"

using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::setprecision;
using std::ofstream;
using std::string;

class NumberCruncher
{
	public:
		NumberCruncher();
		~NumberCruncher();

		double max;
		double scalar;

		bool normalize(Animation &data);
		//bool calcDistance(Animation &data, const char output[]);
		//bool fileToFileDistance(Matrix &table);

	private:
		bool centerBase(Animation &data);
		bool scaleData(Animation &data);
		//bool writeFile(const char outputFile[], Animation &data);
		//bool distanceBetween(Animation &data1, Animation &data2, Matrix &table);
		
};










#endif


