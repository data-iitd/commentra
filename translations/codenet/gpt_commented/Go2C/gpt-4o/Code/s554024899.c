#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#define MAX_CATEGORIES 3
#define MAX_NUMBERS 7

int main() {
    // Initialize a 2D array where each sub-array represents a category of numbers
    int a[MAX_CATEGORIES][MAX_NUMBERS] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };

    int x, y;
    // Read two integers from input
    scanf("%d %d", &x, &y);

=======
int main() {
    // Initialize variables to store the input integers
    int x, y;
    
    // Define a 2D array where each sub-array represents a category of numbers
    int a[3][7] = {
        {1, 3, 5, 7, 8, 10, 12}, // Category 0
        {4, 6, 9, 11},           // Category 1
        {2}                      // Category 2
    };
    
    // Read two integers from input
    scanf("%d %d", &x, &y);
    
>>>>>>> 98c87cb78a (data updated)
    // Initialize variables to store the category indices of x and y
    int xt = -1, yt = -1;

    // Iterate through the categories to find the indices of x and y
<<<<<<< HEAD
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_NUMBERS && a[i][j] != 0; j++) {
=======
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (i == 0 ? 7 : (i == 1 ? 4 : 1)); j++) {
>>>>>>> 98c87cb78a (data updated)
            // Check if the current number matches x
            if (x == a[i][j]) {
                xt = i; // Store the category index for x
            }
            // Check if the current number matches y
            if (y == a[i][j]) {
                yt = i; // Store the category index for y
            }
        }
    }

    // Compare the category indices of x and y and print the result
    if (xt == yt) {
        printf("Yes\n"); // x and y belong to the same category
    } else {
        printf("No\n");  // x and y belong to different categories
    }

    return 0;
}

<<<<<<< HEAD
// max function is not needed in this translation as it is not used in the logic
=======
>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
