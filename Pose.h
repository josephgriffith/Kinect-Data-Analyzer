

#ifndef POSE_H
#define POSE_H

#include <vector>
using std::vector;
#include "Point3D.h"
class Distance;
#include "Distance.h"
using std::endl;

class Pose
{
	public:
		Pose();
		~Pose();

		vector<Point3D> frame;

		inline unsigned int size() const { return frame.size(); }
		inline void push_back(Point3D point) { frame.push_back(point); }
		inline void reserve(int i) { frame.reserve(i); }
		inline void reserve(unsigned int i) { frame.reserve(i); }
		inline void clear() { frame.clear(); }

		inline const Point3D& operator [] (int i) const { return frame[i]; }
		inline Point3D& operator [] (int i) { return frame[i]; }

		double poseDistance(const Pose &pose, const Distance *dist) const;

private:


};

#endif


