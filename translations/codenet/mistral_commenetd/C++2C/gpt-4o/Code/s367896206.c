#include <stdio.h>
#include <stdbool.h>

// Define a struct named Cube with an array 'f' of size 6
typedef struct {
    int f[6]; // Initialize an integer array 'f' of size 6
} Cube;

// Function to roll the cube along z-axis
void roll_z(Cube *c) { 
    int t = c->f[1]; 
    c->f[1] = c->f[2]; 
    c->f[2] = c->f[4]; 
    c->f[4] = c->f[3]; 
    c->f[3] = t; 
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
bool eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) // Iterate through each element of the first cube 'c1'
        if (c1.f[i] != c2.f[i]) // If any element is not equal, return false
            return false;
    return true; // If all elements are equal, return true
}

// Function to check if two cubes are equal after rolling
bool equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) { // Iterate through each rolling direction for the first cube 'c1'
        for (int j = 0; j < 4; j++) { // Iterate through each rolling step in the current direction
            if (eq(c1, c2)) // If the cubes are equal, return true
                return true;
            roll_z(&c1); // Roll the cube along z-axis
        }
        if (i % 2 == 0) roll_y(&c1); // Roll the cube along y-axis if the current index 'i' is even
        else roll_x(&c1); // Roll the cube along x-axis if the current index 'i' is odd
    }
    return false; // If the cubes are not equal after all rolling directions and steps, return false
}

// Main function to read the cubes' states and compare them
int main() {
    Cube c1, c2; // Initialize two empty cubes 'c1' and 'c2'

    // Read the states of the cubes from the standard input
    for (int i = 0; i < 6; i++) scanf("%d", &c1.f[i]);
    for (int i = 0; i < 6; i++) scanf("%d", &c2.f[i]);

    // Compare the cubes and print the result
    if (equal(c1, c2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

// <END-OF-CODE>
