#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
using std::vector;
#include "Point3D.h"
#include "Pose.h"
#include "Distance.h"

class Animation
{
	public:
		Animation();
		~Animation();


		vector<Pose> animation;
		int thing;
		unsigned int start; 
		unsigned int stop;
		unsigned int n;

		inline unsigned int size() const { return animation.size(); }
		inline void push_back(Pose pose) { animation.push_back(pose); }
		inline void reserve(int i) { animation.reserve(i); }
		inline void reserve(unsigned int i) { animation.reserve(i); }
		inline void clear() { animation.clear(); }

		void animationDistance(const Animation &other, vector<vector<double>> &matrix, const Distance *distance);


		inline const Pose& operator [] (int i) const { return animation[i]; }
		inline Pose& operator [] (int i) { return animation[i]; }

	private:


};




#endif


