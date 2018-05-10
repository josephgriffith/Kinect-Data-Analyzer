
#ifndef LINF_DISTANCE_H
#define LINF_DISTANCE_H

#include "Pose.h"
#include <vector>
#include <iostream>
#include <algorithm>
using std::sort;
using std::vector;
using std::cout;
using std::endl;

class LinfDistance : public Distance
{
	public:
		virtual double operator() (const Pose &pose1, const Pose &pose2) const;
};


#endif