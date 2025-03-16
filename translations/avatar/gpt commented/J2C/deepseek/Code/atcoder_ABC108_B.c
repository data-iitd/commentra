#include <stdio.h>

// Function to calculate the new position based on two input positions
int* revpos(int* p, int* q) {
    // Initialize a vector to hold the difference between the two positions
    static int vec[2];
    
    // Calculate the difference between position p and q
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    
    // Rotate the vector to get the new direction
    int tmp = 0;
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    
    // Initialize a new position array
    static int newpos[2];
    
    // Calculate the new position by adding the rotated vector to position q
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    
    // Return the newly calculated position
    return newpos;
}

int main() {
    // Array to hold the input values
    int input[4];
    
    // Read four integers from the user input
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    
    // Initialize a 2D array to hold positions
    int position[4][2];
    
    // Assign input values to the first two positions
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    
    // Calculate the new position based on the first two positions
    int* newpos1 = revpos(position[0], position[1]);
    position[2][0] = newpos1[0];
    position[2][1] = newpos1[1];
    
    // Calculate another new position based on the second and third positions
    int* newpos2 = revpos(position[1], position[2]);
    position[3][0] = newpos2[0];
    position[3][1] = newpos2[1];
    
    // Check if the first position is equal to the result of revpos on the last two positions
    int* checkpos = revpos(position[2], position[3]);
    if (position[0][0] == checkpos[0] && position[0][1] == checkpos[1]) {
        printf("OK\n");
    }
    
    // Prepare an output array to hold the results
    int output[4];
    
    // Assign the calculated positions to the output array
    output[0] = position[2][0];
    output[1] = position[2][1];
    output[2] = position[3][0];
    output[3] = position[3][1];
    
    // Print the output values
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }
    
    return 0;
}
