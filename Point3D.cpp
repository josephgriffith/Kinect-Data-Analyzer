#include "Point3D.h"

double Point3D::getMax()
{
	double max = 0;
	double xyz[] = { x,y,z };

	for (int i = 0; i < 3; i++)
	{
		if (xyz[i] < 0)
			xyz[i] *= -1;
	}

	if (xyz[0] >= xyz[1])
	{
		if (xyz[0] >= xyz[2])
		{
			max = xyz[0];
		}
	}
	else if (xyz[1] >= xyz[2])
		max = xyz[1];
	else
		max = xyz[2];

	return max;
}


