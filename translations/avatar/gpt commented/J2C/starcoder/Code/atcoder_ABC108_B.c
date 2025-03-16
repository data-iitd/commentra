#include <stdio.h>

int main() {
    // Array to hold the input values
    int input[4];
    
    // Read four integers from the user input
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    
    // Array to hold positions
    int position[4][2];
    
    // Assign input values to the first two positions
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    
    // Calculate the new position based on the first two positions
    position[2][0] = position[0][0] - position[1][0];
    position[2][1] = position[0][1] - position[1][1];
    
    // Calculate another new position based on the second and third positions
    position[3][0] = position[1][0] - position[2][0];
    position[3][1] = position[1][1] - position[2][1];
    
    // Check if the first position is equal to the result of revpos on the last two positions
    if (position[0][0] == position[2][0] + position[3][0] && position[0][1] == position[2][1] + position[3][1]) {
        printf("OK\n");
    }
    
    // Array to hold the output values
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

