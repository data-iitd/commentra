#include <stdio.h>

// Represents a cube with six faces, each face having an integer value.
typedef struct {
    int f[6];
} Cube;

// Rotates the cube around the z-axis.
<<<<<<< HEAD
void roll_z(Cube* cube) {
    roll(cube, 1, 2, 4, 3);
}

// Rotates the cube around the y-axis.
void roll_y(Cube* cube) {
    roll(cube, 0, 2, 5, 3);
}

// Rotates the cube around the x-axis.
void roll_x(Cube* cube) {
    roll(cube, 0, 1, 5, 4);
}
=======
void roll_z(Cube* cube) { roll(cube, 1, 2, 4, 3); }

// Rotates the cube around the y-axis.
void roll_y(Cube* cube) { roll(cube, 0, 2, 5, 3); }

// Rotates the cube around the x-axis.
void roll_x(Cube* cube) { roll(cube, 0, 1, 5, 4); }
>>>>>>> 98c87cb78a (data updated)

// Helper method to rotate the cube by swapping the values of the faces.
void roll(Cube* cube, int i, int j, int k, int l) {
    int t = cube->f[i];
    cube->f[i] = cube->f[j];
    cube->f[j] = cube->f[k];
    cube->f[k] = cube->f[l];
    cube->f[l] = t;
}

<<<<<<< HEAD
=======
// Example usage (optional, can be removed)
int main() {
    Cube cube = { {1, 2, 3, 4, 5, 6} };
    roll_z(&cube);
    for (int i = 0; i < 6; i++) {
        printf("%d ", cube.f[i]);
    }
    return 0;
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
