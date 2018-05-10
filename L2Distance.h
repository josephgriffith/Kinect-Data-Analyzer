
#ifndef L2_DISTANCE_H
#define L2_DISTANCE_H

#include "Pose.h"
#include <vector>
#include <iostream>
#include <math.h>
using std::vector;
using std::cout;
using std::endl;

class L2Distance : public Distance
{
	public:
		virtual double operator() (const Pose &pose1, const Pose &pose2) const;

};


#endif