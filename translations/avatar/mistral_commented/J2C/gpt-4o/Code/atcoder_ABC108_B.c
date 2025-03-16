#include <stdio.h>

// Function to reverse the order of elements in an array
void revpos(int p[], int q[], int newpos[]) {
    int vec[2] = {0, 0}; // Initialize a temporary vector with zeros

    // Calculate the differences
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i]; // Subtract corresponding elements of p and q
    }

    // Swap the first and second elements of the vector
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;

    // Calculate the new positions
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
}

// Main function to read input and perform the required calculations
int main() {
    // Read four integers as input
    int input[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]); // Read an integer from the standard input
    }

    // Define a 2D array to store the positions of the four integers
    int position[2][2] = { {0, 0}, {0, 0} };
    position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
    position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
    position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
    position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

    // Calculate the reversed positions of the first and second positions
    int reversedPositions[2][2];
    revpos(position[0], position[1], reversedPositions[0]);
    revpos(position[1], position[0], reversedPositions[1]);

    // Check if the first and second reversed positions are equal
    if (position[0][0] == reversedPositions[1][0] && position[0][1] == reversedPositions[1][1]) {
        printf("OK\n"); // Print "OK" if they are equal
    }

    // Calculate the output array by taking the reversed positions
    int output[4] = {0, 0, 0, 0};
    output[0] = reversedPositions[0][0]; // Store the x-coordinate of the reversed first position
    output[1] = reversedPositions[0][1]; // Store the y-coordinate of the reversed first position
    output[2] = reversedPositions[1][0]; // Store the x-coordinate of the reversed second position
    output[3] = reversedPositions[1][1]; // Store the y-coordinate of the reversed second position

    // Print the output array
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}

// <END-OF-CODE>
