#include "NumberCruncher.h"

NumberCruncher::NumberCruncher()
{
}
NumberCruncher::~NumberCruncher()
{
}

bool NumberCruncher::normalize(Animation &video)
{
	max = 0;
	scalar = 0;

	if (!centerBase(video))
	{
		cout << "error: normalize() - centerBase false!" << endl;
		return false;
	}

	if (max != 1)
	{
		scalar = 1 / max;
		if (!scaleData(video))
		{
			cout << "error: normalize() - scaleData false!" << endl;
			return false;
		}
		else
		{	;	}
	}
	else
	{	;	}

	return true;
}
bool NumberCruncher::centerBase(Animation &video)
{
	Point3D averageBase(0,0,0);

	for (unsigned int i = 0; i < video.size(); i++)
	{
		averageBase.add(video[i][0]);
	}

	averageBase.scaleDivide(video.size());

	double pointMax = -1;
	for (unsigned int i = 0; i < video.size(); i++)
	{
		for (unsigned int j = 0; j < video[i].size(); j++)
		{
			video[i][j].subtract(averageBase);

			pointMax = video[i][j].getMax();
			if (max < pointMax)
			{
				max = pointMax;
			}
		}
	}

	return true;
}
bool NumberCruncher::scaleData(Animation &video)
{
	for (unsigned int i = 0; i < video.size(); i++)
	{
		for (unsigned int j = 0; j < video[i].size(); j++)
		{
			video[i][j].scaleMultiply(scalar);

			if (video[i][j].getMax() > 1)
			{
				cerr << "error: scaleData() - scaled data magnitude larger than 1 on data line " << i+1 << endl;
				return false;
			}
		}
	}

	return true;
}

//PA3
/*******************************************************************************
calcDistance() -	calculates the distances from one frame to the next frame in
						supplied data, and writes them to the supplied file
arguments -			reference to an data to work on, file name for output
returns -			true/false for succeed/fail
*******************************************************************************/
//bool NumberCruncher::calcDistance(Animation &video, const char output[])
//{
//	if (video.size() < 2)
//	{
//		cerr << "error: calcDistance() - animation size < 2" << endl;
//		return false;
//	}
//
//	for (unsigned int i = 0; i < video.size()-1; i++)				//stop one before the last element
//	{
//		video.frameDistance.push_back(0);
//
//		for (unsigned int j = 0; j < video[i].size(); j++)
//		{
//			video.frameDistance[i] = video.frameDistance[i] + video[i][j].distanceFromPoint(video[i + 1][j]);
//			//cout << "calcDistance - point distance: " << video[i][j].distanceFromPoint(video[i + 1][j]) << endl;
//		}
//	}
//	if (!writeFile(output, video))
//	{
//		cerr << "error: calcDistance() - writeFile failed" << endl;
//		return false;
//	}
//
//	return true;
//}
/*******************************************************************************
writeFile() -	writes a file from an Animation's distance member
arguments -		file name to write to, reference to data to output
returns -		true/false for succeed/fail
*******************************************************************************/
//bool NumberCruncher::writeFile(const char outputFile[], Animation &video)
//{
//	ofstream fout;
//	fout.open(outputFile);
//	if (!fout.is_open())
//	{
//		string file = outputFile;
//		cerr << "error: writeFile() - unable to open output file '" << file << "', file name may not be second argument, or may not have file permission" << endl;
//		return false;
//	}
//
//	for (unsigned int i = 0; i < video.size()-1; i++)
//	{
//		fout << fixed << setprecision(8) << video.frameDistance[i] << endl;
//	}
//	fout.close();
//
//	return true;
//}

//PA4
/*******************************************************************************
fileToFileDistance() -	calculates the distances from every frame of a short 
							file to every frame of a >= file, and writes them to 
							the supplied output file
arguments -				a reference to a Matrix containing two sets of data, 
							file name to output to
returns -				true/false for succeed/fail
*******************************************************************************/
//bool NumberCruncher::fileToFileDistance(Matrix &table)
//{
//	if (table.data1.size() == 0)
//	{
//		cerr << "error: fileToFileDistance() - animation 1 size == 0" << endl;
//		return false;
//	}
//	if (table.data2.size() == 0)
//	{
//		cerr << "error: fileToFileDistance() - animation 2 size == 0" << endl;
//		return false;
//	}
//
//	table.sortFiles();
//
//	if (table.sort == 1)
//	{
//		if (!distanceBetween(table.data1, table.data2, table))
//		{
//			cerr << "error: fileToFileDistance() - distanceBetween failed, 1 < 2" << endl;
//			return false;
//		}
//	}
//	else if (table.sort == 2)
//	{
//		if (!distanceBetween(table.data2, table.data1, table))
//		{
//			cerr << "error: fileToFileDistance() - distanceBetween failed, 2 < 1" << endl;
//			return false;
//		}
//	}
//	else
//	{	cout << "error? fileToFileDistance() - sort not set!!";	}
//
//	return true;
//}
/*******************************************************************************
distanceBetween() -	calculates the distance between all poses in two animations
arguments -			two ordered references to Animations sorted ascending, and
						a reference to a Matrix to populate
returns -			true/false for succeed/fail
*******************************************************************************/
//bool NumberCruncher::distanceBetween(Animation &small, Animation &large, Matrix &table)
//{
//	for (unsigned int i = 0; i < small.size(); i++)					//every line in small
//	{
//		if (small[i].size() != 25)
//		{
//			cerr << "error: fileToFileDistance() - animation 1 pose " << i+1 << " size != 25" << endl;
//			return false;
//		}
//
//		for (unsigned int j = 0; j < large.size(); j++)				//every line in large
//		{
//			if (large[j].size() != 25)
//			{
//				cerr << "error: fileToFileDistance() - animation 2 pose " << i+1 << " size != 25" << endl;
//				return false;
//			}
//
//			table.row.push_back(0);
//
//			for (unsigned int k = 0; k < 25; k++)									//all 25 points on a line
//			{
//				table.row[j] += small[i][k].distanceFromPoint(large[j][k]);
//			}
//			//table.row.push_back(data1.frameDistance[j]);
//			//cout << fixed << setprecision(8) << table.row[j] << "\t";
//		}
//
//		table.matrix.push_back(table.row);
//		table.row.clear();
//	}
//
//	return true;
//}
