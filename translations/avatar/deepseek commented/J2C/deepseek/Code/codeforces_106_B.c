#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500

int main() {
    int n;
    int vec[MAX_N][4];
    int ans = 500;
    int ansprice = 20000;

    // Read the number of elements
    scanf("%d", &n);

    // Read the elements into the 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &vec[i][j]);
        }
    }

    // Loop through each element to find the best one
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the element is dominated

        // Compare the current element with every other element
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = 0; // The element is dominated
            }
        }

        // If the element is not dominated, check its price
        if (fl == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the minimum price
                ans = i + 1; // Update the best index
            }
        }
    }

    // Output the index of the best element
    printf("%d\n", ans);

    return 0;
}
