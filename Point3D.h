/*! \file Point3D.h
	\brief Contains the Point3D class declaration (header)
	Unless/until extended by students, there is no Point3D.cpp file, as all the methods of Point3D are inline.
*/

#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

#include<iostream>
#include <math.h>

using std::ostream;

//! Real-valued points in 3 space, i.e. (x, y, z)
/*! 
  Point3D is the base class for storing points in 3 space and accessing their coordinates. The
  PoseDisplay class will write out and display vectors of 25 Point3Ds (obviously, their order matters!).
  
  The Point3D class as implemented here is sufficient for Programming Assignment #1. As the semester
  progresses, however, students are encouraged to extend this class by adding new methods, new overloaded
  operators, and new data fields as necessary. As long as the X(), Y(), Z() methods and the << operator
  below are retained, the PoseDisplay class will work with modifications of the Pose3D class. Students
  are also encouraged new classes, including classes that might contain Point3D fields.
 */
class Point3D {
	public:
		/// Constructor with up to 3 coordinate arguments. All arguments default to -4.
		Point3D(double x = -4.0, double y = -4.0, double z = -4.0) : x(x), y(y), z(z) {}

		inline double X() const { return x; }          //!< Return the X coordinate of the point
		inline double Y() const { return y; }          //!< Return the Y coordinate of the point
		inline double Z() const { return z; }          //!< Return the Z coordindate of the point
		
		double getMax();		//not inline

		inline void setX(double num) { x = num; }          //!< set the X coordinate of the point
		inline void setY(double num) { y = num; }          //!< set the Y coordinate of the point
		inline void setZ(double num) { z = num; }          //!< set the Z coordindate of the point

		inline bool isZero() { if (X() == 0 && Z() == 0 && Z() == 0) { return true; } else { return false; } }
		inline void add(Point3D point) { x += point.X(); y += point.Y(); z += point.Z(); }
		inline void subtract(Point3D point) { x -= point.X(); y -= point.Y(); z -= point.Z(); }
		inline void scaleDivide(double num) { x /= num; y /= num; z /= num; }
		inline void scaleMultiply(double num) { x *= num; y *= num; z *= num; }

		inline double distanceFromPoint(const Point3D &point) const { return sqrt( ((x-point.X())*(x-point.X())) + ((y-point.Y())*(y-point.Y())) + ((z-point.Z())*(z-point.Z())) ); }

	protected:
		double x;                                     //!< x coordinate (real value)
		double y;                                     //!< y coordinate (real value)
		double z;                                     //!< z coordinate (real value)
};

/// Overload of << operator for Point3D. Prints out as three real values, separated by spaces with a trailing space.
inline ostream& operator << (ostream& ostr, const Point3D& pt) { ostr << pt.X() << " " << pt.Y() << " " << pt.Z() << " "; return ostr; }

#endif // POINT3D_H_INCLUDED
