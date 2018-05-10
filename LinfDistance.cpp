
#include "LinfDistance.h"

double LinfDistance::operator() (const Pose &pose1, const Pose &pose2) const
{
	double max = -1;
	double check;

	for (unsigned int k = 0; k < 25; k++)
	{
		check = pose1.frame[k].distanceFromPoint(pose2.frame[k]);
		if (check > max)
		{
			max = check;
		}
	}

	return max;
}


