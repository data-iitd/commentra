#include<iostream>
using namespace std;

// Represents a cube with six faces, each face having an integer value.
class Cube {
public:
	int f[6];
	Cube() {}
	
	// Rotates the cube around the z-axis.
	void roll_z() { roll(1, 2, 4, 3); }
	
	// Rotates the cube around the y-axis.
	void roll_y() { roll(0, 2, 5, 3); }
	
	// Rotates the cube around the x-axis.
	void roll_x() { roll(0, 1, 5, 4); }
	
	// Helper method to rotate the cube by swapping the values of the faces.
	void roll(int i, int j, int k, int l) {
		int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
	}
};