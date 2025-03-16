
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables for the number of people (n) and the number of food items (m)
    int n, m;
    scanf("%d %d", &n, &m); // Input the values of n and m

    // Create an array to count the number of people who like each food item
    int* foods = (int*)malloc(m * sizeof(int));

    // Loop through each person to gather their food preferences
    for (int i = 0; i < n; i++) {
        int k; // Number of food items the current person likes
        scanf("%d", &k); // Input the number of food items

        // Loop through each food item liked by the current person
        for (int j = 0; j < k; j++) {
            int temp; // Temporary variable to hold the food item index
            scanf("%d", &temp); // Input the food item index
            temp--; // Convert to zero-based index

            // Increment the count for the corresponding food item
            foods[temp]++;
        }
    }

    // Initialize a counter for the number of food items liked by all people
    int ans = 0;
    // Loop through the food counts to find how many are liked by all n people
    for (int i = 0; i < m; i++) {
        if (foods[i] == n) { // Check if the food item is liked by all n people
            ans++; // Increment the answer if the condition is met
        }
    }

    // Output the total number of food items liked by all people
    printf("%d\n", ans);

    // Free the memory allocated for the foods array
    free(foods);

    return 0;
}
