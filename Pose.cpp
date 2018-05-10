#include "Pose.h"

Pose::Pose()
{
}
Pose::~Pose()
{
}

double Pose::poseDistance(const Pose &pose, const Distance *dist) const
{
	return (*dist)(pose, *this);
}


