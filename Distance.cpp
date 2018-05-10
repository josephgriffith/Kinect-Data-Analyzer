
#include "Distance.h"

Distance::Distance()
{
}
Distance::~Distance()
{
}

double Distance::operator() (const Pose &pose1, const Pose &pose2) const
{
	double sum = 0;
	for (unsigned int k = 0; k < 25; k++)
	{
		sum += pose1.frame[k].distanceFromPoint(pose2.frame[k]);
	}

	return sum;
}


