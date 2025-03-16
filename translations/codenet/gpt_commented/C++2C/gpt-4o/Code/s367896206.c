#include <stdio.h>
#include <stdbool.h>

// Structure representing a Cube with 6 faces
typedef struct {
    int f[6]; // Array to hold the values of the cube's faces
} Cube;

// Method to roll the cube around the Z-axis
void roll_z(Cube *c) { roll(c, 1, 2, 4, 3); }

// Method to roll the cube around the Y-axis
void roll_y(Cube *c) { roll(c, 0, 2, 5, 3); }

// Method to roll the cube around the X-axis
void roll_x(Cube *c) { roll(c, 0, 1, 5, 4); }

// Method to perform a roll operation on specified faces
void roll(Cube *c, int i, int j, int k, int l) {
    int t = c->f[i]; // Store the value of face i temporarily
    c->f[i] = c->f[j];  // Move value of face j to face i
    c->f[j] = c->f[k];  // Move value of face k to face j
    c->f[k] = c->f[l];  // Move value of face l to face k
<<<<<<< HEAD
    c->f[l] = t;     // Assign the temporary value to face l
=======
    c->f[l] = t;        // Assign the temporary value to face l
>>>>>>> 98c87cb78a (data updated)
}

// Function to check if two cubes are equal
bool eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++)
        if (c1.f[i] != c2.f[i]) return false; // Return false if any face differs
    return true; // Return true if all faces are equal
}

// Function to check if two cubes can be made equal through rotations
bool equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) { // Iterate through each face of the cube
        for (int j = 0; j < 4; j++) { // Try 4 rotations around the Z-axis
            if (eq(c1, c2)) return true; // Check if cubes are equal after rotation
            roll_z(&c1); // Roll the cube around the Z-axis
        }
        // Alternate rolling around Y and X axes based on the iteration index
        if (i % 2 == 0) roll_y(&c1); // Roll around Y-axis for even indices
        else roll_x(&c1); // Roll around X-axis for odd indices
    }
    return false; // Return false if no configuration matches
}

int main() {
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

// <END-OF-CODE>
