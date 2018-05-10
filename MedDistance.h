
#ifndef MED_DISTANCE_H
#define MED_DISTANCE_H

#include "Pose.h"
#include <vector>
#include <iostream>
#include <algorithm>
using std::nth_element;
using std::sort;
using std::vector;
using std::cout;
using std::endl;

class MedDistance : public Distance
{
	public:
		virtual double operator() (const Pose &pose1, const Pose &pose2) const;
};


#endif