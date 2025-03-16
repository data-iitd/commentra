#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    // Declare variables
    int n, m;
    int foods[m];

    // Read input values
    scanf("%d %d", &n, &m);

    // Initialize a vector of size m to store the count of each food item
    int foods[m];

    // Read n food preferences from the standard input
    for (int i = 0; i < n; i++) {
        int k;

        // Read the number of food items in the current preference
        scanf("%d", &k);

        // Read the indices of the food items in the current preference
        for (int j = 0; j < k; j++) {
            int temp;

            // Read the index of the current food item
            scanf("%d", &temp);

            // Increment the count of the corresponding food item in the foods vector
            foods[temp]++;
        }
    }

    // Initialize a variable to store the number of food items that appear in all preferences
    int ans = 0;

    // Iterate through each element in the foods vector and check if its count is equal to the total number of preferences
    for (int i = 0; i < m; i++) {
        if (foods[i] == n) {
            ans++;
        }
    }

    // Print the value of ans to the standard output
    printf("%d\n", ans);
}

