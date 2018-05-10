#include "Parser.h"

Parser::Parser()
{
}
Parser::~Parser()
{	
}

bool Parser::getAnimation(Animation &video)
{
	numCount = 0;
	linenum = 0;
	blanks = 0;
	string line = "STARTING VALUE";

	video.clear();

	while (!fin.eof())			//loop through all lines of the file
	{
		nextLine(line);

		if (!fin.good() && blanks > 1)
		{
			cerr << "error: getAnimation() - string stream failed on line " << linenum << endl;
			return false;
		}

		if (!getPose())
		{
			cerr << "error: getAnimation() - getPose failed " << endl;
			return false;
		}

		if (pose.size() != 25 && !fin.eof())	
		{
			cerr << "error: getAnimation() - fewer that 75 numbers (or blank line) on line " << linenum << endl;
			return false;
		}
		else if (pose.size() == 25)
		{
			video.animation.push_back(pose);
		}

		pose.clear();
	}
	fin.close();

	return true;
}
void Parser::nextLine(string &line)
{
	getline(fin, line);

	linenum++;

	int end = line.size() - 1;
	if (end == -1 || end == 0)
	{
		blanks++;
	}
	else
	{
		while (line[end] == ' ' || line[end] == '\t' || line[end] == '\v' || line[end] == '\f')
		{
			line.resize(end);
		}
	}

	sstream.clear();
	sstream << line;		//does not change line
}
bool Parser::getPose()
{
	numCount = 0;

	while (!sstream.eof())				//loop through every number on one line
	{
		if (!getPoint())
		{
			cerr << "error: getPose() - getPoint failed on " << linenum << endl;
			return false;
		}

		if (numCount % 3 == 0)
		{
			pose.push_back(point);
		}
	}

	if (pose.size() != 25 && blanks > 1)
	{
		cerr << "error: getPose() - not 25 points on line " << linenum << endl;
		return false;
	}

	return true;
}
bool Parser::getPoint()
{
	double token;

	int i = 0;
	do
	{
		sstream >> token;
		if (!sstream.eof() && numCount + 1 > 75)
		{
			cerr << "error: getPoint() - more than 75 numbers on line " << linenum << endl;
			return false;
		}
		else if (!sstream.good())
		{
			cerr << "error: getPoint() - string stream failed on line " << linenum << endl;
			return false;
		}
		numCount++;
		switch (i)
		{
			case 0:
				point.setX(token);
				break;
			case 1:
				point.setY(token);
				break;
			case 2:
				point.setZ(token);
				break;
			default:
				cerr << "error: getPoint() - getPoint j not 0-2, ???" << linenum << endl;
		}
		i++;
	} while (i < 3 && !sstream.eof());

	return true;
}

bool Parser::openInputFile(const char input[])
{
	fin.open(input);
	if (!fin.is_open())
	{
		string file = input;
		cerr << "error: openInputFile() - unable to open output file '" << file << "', file name may not be second argument, may not have file permission" << endl;
		return false;
	}


	return true;
}
