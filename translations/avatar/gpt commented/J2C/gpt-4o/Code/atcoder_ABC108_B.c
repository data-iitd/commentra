#include <stdio.h>

// Function to calculate the new position based on two input positions
void revpos(int p[2], int q[2], int newpos[2]) {
    // Initialize a vector to hold the difference between the two positions
    int vec[2] = {0, 0};
    
    // Calculate the difference between position p and q
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    
    // Rotate the vector to get the new direction
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    
    // Calculate the new position by adding the rotated vector to position q
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
}

int main() {
    // Array to hold the input values
    int input[4] = {0, 0, 0, 0};
    
    // Read four integers from the user input
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    
    // Initialize a 2D array to hold positions
    int position[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    
    // Assign input values to the first two positions
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    
    // Calculate the new position based on the first two positions
    revpos(position[0], position[1], position[2]);
    
    // Calculate another new position based on the second and third positions
    revpos(position[1], position[2], position[3]);
    
    // Check if the first position is equal to the result of revpos on the last two positions
    int check[2];
    revpos(position[2], position[3], check);
    if (position[0][0] == check[0] && position[0][1] == check[1]) {
        printf("OK\n");
    }
    
    // Print the output values
    for (int i = 0; i < 4; i++) {
        printf("%d\n", position[i][0]);
        printf("%d\n", position[i][1]);
    }
    
    return 0;
}

// <END-OF-CODE>
