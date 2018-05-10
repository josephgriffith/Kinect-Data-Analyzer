
#include "Animation.h"

Animation::Animation()
{
	thing = 0;
	animation.reserve(500);
}
Animation::~Animation()
{
}

void Animation::animationDistance(const Animation &other, vector<vector<double>> &matrix, const Distance *distance)
{
	vector<double> row;

	for (unsigned int i = 0; i < animation.size(); i++)				//every line in 1
	{
		for (unsigned int j = 0; j < other.size(); j++)				//every line in 2
		{
			row.push_back(animation[i].poseDistance(other[j], distance));
		}

		matrix.push_back(row);
		row.clear();
	}
}


