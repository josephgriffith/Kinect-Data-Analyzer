
#include "AvgDistance.h"

double AvgDistance::operator() (const Pose &pose1, const Pose &pose2) const
{
	double sum = 0;
	for (unsigned int k = 0; k < 25; k++)
	{
		sum += pose1.frame[k].distanceFromPoint(pose2.frame[k]);
	}
	sum /= 25;

	return sum;
}


