#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Point3D.h"
#include "PoseDisplay.h"
#include "Animation.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::stringstream;

class Parser
{
	public:
		Parser();
		~Parser();

		bool openInputFile(char const input[]);
		bool getAnimation(Animation &video);

	private:
		int blanks;
		int linenum;
		int numCount;
		Point3D point;
		Pose pose;
		ifstream fin;
		stringstream sstream;

		void nextLine(string &line);

		bool getPose();
		bool getPoint();

};










#endif




