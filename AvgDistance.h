
#ifndef AVG_DISTANCE_H
#define AVG_DISTANCE_H

#include "Pose.h"
#include <iostream>
using std::cout;
using std::endl;

class AvgDistance : public Distance
{
	public:
		virtual double operator() (const Pose &pose1, const Pose &pose2) const;
};


#endif