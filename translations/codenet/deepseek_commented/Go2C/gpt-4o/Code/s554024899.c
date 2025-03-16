#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 98c87cb78a (data updated)

// Function to read the next integer from input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int main() {
    // Read two integers from the input
    int x = nextInt();
    int y = nextInt();
    
<<<<<<< HEAD
    // Define an array containing three arrays, each representing a group of months with the same number of days
    int *a[3];
    int group1[] = {1, 3, 5, 7, 8, 10, 12};
    int group2[] = {4, 6, 9, 11};
    int group3[] = {2};
    
    a[0] = group1;
    a[1] = group2;
    a[2] = group3;

=======
    // Define an array containing three groups of months with the same number of days
    int months[3][12] = {
        {1, 3, 5, 7, 8, 10, 12}, // 31 days
        {4, 6, 9, 11},           // 30 days
        {2}                      // February
    };
    
>>>>>>> 98c87cb78a (data updated)
    int xt = -1, yt = -1;

    // Iterate over the array to determine which group each of the integers belongs to
    for (int i = 0; i < 3; i++) {
<<<<<<< HEAD
        int *group = a[i];
        int size = (i == 0) ? 7 : (i == 1) ? 4 : 1; // Sizes of the groups
        for (int j = 0; j < size; j++) {
            if (x == group[j]) {
                xt = i;
            }
            if (y == group[j]) {
=======
        for (int j = 0; j < 12 && months[i][j] != 0; j++) {
            if (x == months[i][j]) {
                xt = i;
            }
            if (y == months[i][j]) {
>>>>>>> 98c87cb78a (data updated)
                yt = i;
            }
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Compare the groups of x and y to determine if they belong to the same group
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
