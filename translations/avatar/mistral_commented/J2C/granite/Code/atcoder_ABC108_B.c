

#include <stdio.h>

// Define a function to reverse the order of elements in an array
void revpos(int p[], int q[], int vec[]) {
    int i;
    for (i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i]; // Subtract corresponding elements of p and q and store the result in vec[i]
    }
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp; // Swap the first and second elements of the vector
}

// Define the main function to read input and perform the required calculations
int main() {
    int input[4];
    int position[2][2];
    int reversedPositions[2][2];
    int output[4];

    // Read four integers as input and store them in an array
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]); // Read an integer from the standard input stream and store it in input[i]
    }

    // Define a 2D array to store the positions of the four integers
    position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
    position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
    position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
    position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

    // Calculate the reversed positions of the first and second positions
    int vec[2];
    revpos(position[0], position[1], vec);
    reversedPositions[0][0] = position[1][0] + vec[0]; // Calculate the x-coordinate of the reversed first position
    reversedPositions[0][1] = position[1][1] + vec[1]; // Calculate the y-coordinate of the reversed first position
    reversedPositions[1][0] = position[0][0] + vec[0]; // Calculate the x-coordinate of the reversed second position
    reversedPositions[1][1] = position[0][1] + vec[1]; // Calculate the y-coordinate of the reversed second position

    // Check if the first and second reversed positions are equal
    if (position[0][0] == reversedPositions[1][0] && position[0][1] == reversedPositions[1][1]) { // Compare the first position with the reversed second position
        printf("OK\n"); // Print "OK" if they are equal
    }

    // Calculate the output array by taking the reversed positions and swapping their x and y coordinates
    output[0] = reversedPositions[1][0]; // Store the x-coordinate of the reversed second position in output[0]
    output[1] = reversedPositions[1][1]; // Store the y-coordinate of the reversed second position in output[1]
    output[2] = reversedPositions[0][0]; // Store the x-coordinate of the reversed first position in output[2]
    output[3] = reversedPositions[0][1]; // Store the y-coordinate of the reversed first position in output[3]

    // Print the output array
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}

