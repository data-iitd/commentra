#include <stdio.h>

// The revpos function calculates the difference between two positions,
// swaps the components of the difference vector, and then adds the modified
// difference vector to the second position.
int* revpos(int* p, int* q) {
    static int vec[2]; // Initialize the vector to store the difference
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i]; // Calculate the difference between p and q
    }
    int tmp = 0; // Temporary variable to swap the components of the vector
    tmp = vec[0]; // Swap the first component
    vec[0] = vec[1]; // Swap the second component to the first position
    vec[1] = -tmp; // Negate the first component and store it in the second position
    static int newpos[2]; // Initialize the new position vector
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i]; // Add the modified difference vector to the second position
    }
    return newpos; // Return the new position
}

int main() {
    int input[4]; // Initialize the input array to store four integers
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]); // Read four integers from the user
    }
    int position[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}}; // Initialize the position array
    position[0][0] = input[0]; // Assign the first integer to the first position's x-coordinate
    position[0][1] = input[1]; // Assign the second integer to the first position's y-coordinate
    position[1][0] = input[2]; // Assign the third integer to the second position's x-coordinate
    position[1][1] = input[3]; // Assign the fourth integer to the second position's y-coordinate
    int* pos2 = revpos(position[0], position[1]); // Compute the new position using revpos
    int* pos3 = revpos(position[1], pos2); // Compute another new position using revpos
    if (position[0][0] == pos3[0] && position[0][1] == pos3[1]) { // Check if the first position is equal to the result of revpos on the second and third positions
        printf("OK\n"); // Print "OK" if they are equal
    }
    int output[4]; // Initialize the output array
    output[0] = pos2[0]; // Assign the x-coordinate of the second new position to the output array
    output[1] = pos2[1]; // Assign the y-coordinate of the second new position to the output array
    output[2] = pos3[0]; // Assign the x-coordinate of the third new position to the output array
    output[3] = pos3[1]; // Assign the y-coordinate of the third new position to the output array
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]); // Print each element of the output array
    }
    return 0;
}
