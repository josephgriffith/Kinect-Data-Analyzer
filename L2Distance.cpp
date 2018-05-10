
#include "L2Distance.h"

double L2Distance::operator() (const Pose &pose1, const Pose &pose2) const
{
	double euclidean = 0;
	for (unsigned int k = 0; k < 25; k++)
	{
		euclidean += pow(pose1.frame[k].distanceFromPoint(pose2.frame[k]), 2);
	}
	euclidean = sqrt(euclidean);

	return euclidean;
}


