#include<stdio.h>

// Class representing a Cube with 6 faces
typedef struct {
    int f[6]; // Array to hold the values of the cube's faces
} Cube;

// Function to check if two cubes are equal
int eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++)
        if (c1.f[i]!= c2.f[i]) return 0; // Return false if any face differs
    return 1; // Return true if all faces are equal
}

// Function to check if two cubes can be made equal through rotations
int equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) { // Iterate through each face of the cube
        for (int j = 0; j < 4; j++) { // Try 4 rotations around the Z-axis
            if (eq(c1, c2)) return 1; // Check if cubes are equal after rotation
            roll_z(c1); // Roll the cube around the Z-axis
        }
        // Alternate rolling around Y and X axes based on the iteration index
        if (i % 2 == 0) roll_y(c1); // Roll around Y-axis for even indices
        else roll_x(c1); // Roll around X-axis for odd indices
    }
    return 0; // Return false if no configuration matches
}

// Function to roll the cube around the Z-axis
void roll_z(Cube *c) {
    int t = c->f[1]; // Store the value of face 1 temporarily
    c->f[1] = c->f[2];  // Move value of face 2 to face 1
    c->f[2] = c->f[4];  // Move value of face 4 to face 2
    c->f[4] = c->f[3];  // Move value of face 3 to face 4
    c->f[3] = t;     // Assign the temporary value to face 3
}

// Function to roll the cube around the Y-axis
void roll_y(Cube *c) {
    int t = c->f[0]; // Store the value of face 0 temporarily
    c->f[0] = c->f[2];  // Move value of face 2 to face 0
    c->f[2] = c->f[5];  // Move value of face 5 to face 2
    c->f[5] = c->f[3];  // Move value of face 3 to face 5
    c->f[3] = t;     // Assign the temporary value to face 3
}

// Function to roll the cube around the X-axis
void roll_x(Cube *c) {
    int t = c->f[0]; // Store the value of face 0 temporarily
    c->f[0] = c->f[1];  // Move value of face 1 to face 0
    c->f[1] = c->f[5];  // Move value of face 5 to face 1
    c->f[5] = c->f[4];  // Move value of face 4 to face 5
    c->f[4] = t;     // Assign the temporary value to face 4
}

int main()
{
    Cube c1, c2; // Create two Cube objects

    // Input values for the first cube's faces
    for (int i = 0; i < 6; i++) scanf("%d", &c1.f[i]);
    // Input values for the second cube's faces
    for (int i = 0; i < 6; i++) scanf("%d", &c2.f[i]);

    // Check if the two cubes can be made equal and print the result
    if (equal(c1, c2)) printf("Yes\n"); // Print "Yes" if they are equal
    else printf("No\n"); // Print "No" if they are not equal

    return 0; // End of the program
}

