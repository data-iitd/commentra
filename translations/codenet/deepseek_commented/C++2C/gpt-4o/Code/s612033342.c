#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

// Computes 2^a
=======
>>>>>>> 98c87cb78a (data updated)
int pow2(int a) {
    int ret = 1;
    for (int i = 0; i < a; i++) ret *= 2;
    return ret;
}

<<<<<<< HEAD
// Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
int count(Matrix hw, int a, int b) {
    int sum = 0;
    for (int i = 0; i < hw.rows; i++) {
        for (int j = 0; j < hw.cols; j++) {
            if ((a >> i & 1) && (b >> j & 1) && hw.data[i][j] == 1) sum++;
=======
int count(int** hw, int h, int w, int a, int b) {
    int sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((a >> i & 1) && (b >> j & 1) && hw[i][j] == 1) sum++;
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return sum;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    
<<<<<<< HEAD
    // Initialize the grid with dimensions h x w
    Matrix hw;
    hw.rows = h;
    hw.cols = w;
    hw.data = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        hw.data[i] = (int *)malloc(w * sizeof(int));
        for (int j = 0; j < w; j++) {
            hw.data[i][j] = 0; // Fill with 0s
=======
    // Allocate memory for the grid
    int** hw = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        hw[i] = (int*)malloc(w * sizeof(int));
        for (int j = 0; j < w; j++) {
            hw[i][j] = 0; // Initialize with 0s
>>>>>>> 98c87cb78a (data updated)
        }
    }
    
    // Read the grid and set 1s where there is a '#'
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
<<<<<<< HEAD
            scanf(" %c", &c); // Read character
            if (c == '#') hw.data[i][j] = 1;
=======
            scanf(" %c", &c); // Read character input
            if (c == '#') hw[i][j] = 1;
>>>>>>> 98c87cb78a (data updated)
        }
    }
    
    int sum = 0;
    
    // Iterate over all possible combinations of row and column selections
    for (int i = 0; i < pow2(h); i++) {
        for (int j = 0; j < pow2(w); j++) {
<<<<<<< HEAD
            if (count(hw, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
=======
            if (count(hw, h, w, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
>>>>>>> 98c87cb78a (data updated)
        }
    }
    
    // Output the result
    printf("%d\n", sum);
    
    // Free allocated memory
    for (int i = 0; i < h; i++) {
<<<<<<< HEAD
        free(hw.data[i]);
    }
    free(hw.data);
=======
        free(hw[i]);
    }
    free(hw);
>>>>>>> 98c87cb78a (data updated)
    
    return 0;
}

// <END-OF-CODE>
