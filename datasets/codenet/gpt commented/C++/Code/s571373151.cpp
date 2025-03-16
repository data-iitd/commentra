#include <iostream>
#include <vector>

int main()
{
    // Declare variables for the number of people (n) and the number of food items (m)
    int n, m;
    std::cin >> n >> m; // Input the values of n and m

    // Create a vector to count the number of people who like each food item
    std::vector<int> foods(m);

    // Loop through each person to gather their food preferences
    for (int i = 0; i < n; i++) {
        int k; // Number of food items the current person likes
        std::cin >> k; // Input the number of food items

        // Loop through each food item liked by the current person
        for (int j = 0; j < k; j++) {
            int temp; // Temporary variable to hold the food item index
            std::cin >> temp; // Input the food item index
            temp--; // Convert to zero-based index

            // Increment the count for the corresponding food item
            foods[temp]++;
        }
    }

    // Initialize a counter for the number of food items liked by all people
    int ans = 0;
    // Loop through the food counts to find how many are liked by all n people
    for (auto elem : foods) {
        if (elem == n) { // Check if the food item is liked by all n people
            ans++; // Increment the answer if the condition is met
        }
    }

    // Output the total number of food items liked by all people
    std::cout << ans << std::endl;
}
