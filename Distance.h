
#ifndef DISTANCE_H
#define DISTANCE_H

class Pose;
#include "Pose.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Distance
{
	public:
		Distance();
		virtual ~Distance();

		virtual double operator() (const Pose &pose1, const Pose &pose2) const;
};


#endif