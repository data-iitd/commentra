#include <stdio.h>

// Define a struct named Cube with an array 'f' of size 6
typedef struct {
    int f[6];
} Cube;

// Function to roll the cube along z-axis
void roll_z(Cube *c) {
    int t = c->f[1];
    c->f[1] = c->f[4];
    c->f[4] = c->f[3];
    c->f[3] = c->f[2];
    c->f[2] = t;
}

// Function to roll the cube along y-axis
void roll_y(Cube *c) {
    int t = c->f[0];
    c->f[0] = c->f[2];
    c->f[2] = c->f[5];
    c->f[5] = c->f[3];
    c->f[3] = t;
}

// Function to roll the cube along x-axis
void roll_x(Cube *c) {
    int t = c->f[0];
    c->f[0] = c->f[1];
    c->f[1] = c->f[5];
    c->f[5] = c->f[4];
    c->f[4] = t;
}

// Function to check if two cubes are equal
int eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) {
        if (c1.f[i] != c2.f[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if two cubes are equal after rolling
int equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (eq(c1, c2)) {
                return 1;
            }
            roll_z(&c1);
        }
        if (i % 2 == 0) {
            roll_y(&c1);
        } else {
            roll_x(&c1);
        }
    }
    return 0;
}

// Main function to read the cubes' states and compare them
int main() {
    Cube c1, c2;

    // Read the states of the cubes from the standard input
    for (int i = 0; i < 6; i++) {
        scanf("%d", &c1.f[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &c2.f[i]);
    }

    // Compare the cubes and print the result
    if (equal(c1, c2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
