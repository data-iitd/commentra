#include <stdio.h>
#include <stdlib.h>

typedef int** vi2; // Define a shorthand for a vector of vectors of integers

// Function to calculate 2 raised to the power of 'a'
int pow2(int a) {
    int ret = 1; // Initialize result to 1
    for (int i = 0; i < a; i++) ret *= 2; // Multiply by 2, 'a' times
    return ret; // Return the result
}

// Function to count the number of '1's in the hw matrix based on the bit patterns of 'a' and 'b'
int count(vi2 hw, int h, int w, int a, int b) {
    int sum = 0; // Initialize sum to count the valid positions
    // Iterate through each row of the hw matrix
    for (int i = 0; i < h; i++) {
        // Iterate through each column of the hw matrix
        for (int j = 0; j < w; j++) {
            // Check if the i-th bit of 'a' and the j-th bit of 'b' are set, and if hw[i][j] is 1
            if ((a >> i & 1) && (b >> j & 1) && hw[i][j] == 1) sum++;
        }
    }
    return sum; // Return the total count of valid positions
}

int main() {
    // Read the dimensions of the matrix and the target count 'k'
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    
<<<<<<< HEAD
    // Allocate memory for the 2D array
=======
    // Initialize a 2D array with dimensions h x w
>>>>>>> 98c87cb78a (data updated)
    vi2 hw = (vi2)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        hw[i] = (int*)malloc(w * sizeof(int));
    }

    // Read the matrix input
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; 
            scanf(" %c", &c); // Read each character
            // If the character is '#', mark it as 1 in the hw matrix
            if (c == '#') hw[i][j] = 1;
            else hw[i][j] = 0; // Ensure other characters are marked as 0
        }
    }

    int sum = 0; // Initialize sum to count the valid configurations
    // Iterate through all possible combinations of rows (2^h)
    for (int i = 0; i < pow2(h); i++) {
        // Iterate through all possible combinations of columns (2^w)
        for (int j = 0; j < pow2(w); j++) {
            // If the count of '1's matches the target 'k', increment the sum
            if (count(hw, h, w, i, j) == k) sum++;
        }
    }

    printf("%d\n", sum); // Output the total count of valid configurations

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(hw[i]);
    }
    free(hw);

    return 0;
}

// <END-OF-CODE>
