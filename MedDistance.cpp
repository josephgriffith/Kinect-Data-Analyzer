
#include "MedDistance.h"

double MedDistance::operator() (const Pose &pose1, const Pose &pose2) const
{
	vector<double> distances(25);

	for (unsigned int k = 0; k < 25; k++)
	{
		distances[k] = pose1.frame[k].distanceFromPoint(pose2.frame[k]);
	}

	nth_element(distances.begin(), distances.begin() + 12, distances.end());

	return distances[12];
}

