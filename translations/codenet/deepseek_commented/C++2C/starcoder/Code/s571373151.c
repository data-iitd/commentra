#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m); // Read the number of people and the number of food types

    int foods[m]; // Initialize a vector to keep track of food counts

    for (int i = 0; i < n; i++) { // Loop through each person
        int k;
        scanf("%d", &k); // Read the number of food preferences for this person

        for (int j = 0; j < k; j++) { // Loop through each food preference
            int temp;
            scanf("%d", &temp); // Read the type of food
            temp--; // Adjust the food type to be 0-indexed

            foods[temp]++; // Increment the count of this food type
        }
    }

    int ans = 0; // Initialize a counter for food types preferred by all people

    for (int i = 0; i < m; i++) { // Loop through each food type count
        if (foods[i] == n) { // Check if the food type is preferred by all people
            ans++; // Increment the counter
        }
    }

    printf("%d\n", ans); // Output the number of food types preferred by all people
}

