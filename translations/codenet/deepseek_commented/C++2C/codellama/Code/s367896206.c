#include<stdio.h>

// Represents a cube with six faces, each face having an integer value.
struct Cube {
	int f[6];
};

// Rotates the cube around the z-axis.
void roll_z(struct Cube *c) { roll(c, 1, 2, 4, 3); }

// Rotates the cube around the y-axis.
void roll_y(struct Cube *c) { roll(c, 0, 2, 5, 3); }

// Rotates the cube around the x-axis.
void roll_x(struct Cube *c) { roll(c, 0, 1, 5, 4); }

// Helper method to rotate the cube by swapping the values of the faces.
void roll(struct Cube *c, int i, int j, int k, int l) {
	int t = c->f[i]; c->f[i] = c->f[j]; c->f[j] = c->f[k]; c->f[k] = c->f[l]; c->f[l] = t;
}

