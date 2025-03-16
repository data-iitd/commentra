#include <stdio.h>

// Define a function to reverse the order of elements in an array
int* revpos(int* p, int* q, int* vec) {
    vec[0] = p[0] - q[0]; // Subtract corresponding elements of p and q and store the result in vec[0]
    vec[1] = p[1] - q[1]; // Subtract corresponding elements of p and q and store the result in vec[1]

    // Swap the first and second elements of the vector
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;

    // Calculate the new positions by adding the vector elements to the corresponding elements of q
    int newpos[2];
    newpos[0] = q[0] + vec[0];
    newpos[1] = q[1] + vec[1];

    // Return the new positions
    return newpos;
}

// Define the main function to read input and perform the required calculations
int main() {
    // Define an array to store the positions of the four integers
    int input[4];

    // Read four integers as input and store them in an array
    scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);

    // Define a 2D array to store the positions of the four integers
    int position[2][2];
    position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
    position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
    position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
    position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

    // Calculate the reversed positions of the first and second positions
    int reversedPositions[2][2];
    int* rev1 = revpos(position[0], position[1], reversedPositions[0]);
    int* rev2 = revpos(position[1], position[0], reversedPositions[1]);

    // Check if the first and second reversed positions are equal
    if (position[0][0] == rev2[0] && position[0][1] == rev2[1]) { // Compare the first position with the reversed second position
        printf("OK\n"); // Print "OK" if they are equal
    }

    // Calculate the output array by taking the reversed positions and swapping their x and y coordinates
    int output[4];
    output[0] = rev1[0]; // Store the x-coordinate of the reversed third position in output[0]
    output[1] = rev1[1]; // Store the y-coordinate of the reversed third position in output[1]
    output[2] = rev2[0]; // Store the x-coordinate of the reversed fourth position in output[2]
    output[3] = rev2[1]; // Store the y-coordinate of the reversed fourth position in output[3]

    // Print the output array
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}
