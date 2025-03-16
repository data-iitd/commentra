#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m; // Read the number of people and the number of food types

    std::vector<int> foods(m); // Initialize a vector to keep track of food counts

    for (int i = 0; i < n; i++) { // Loop through each person
        int k;
        std::cin >> k; // Read the number of food preferences for this person

        for (int j = 0; j < k; j++) { // Loop through each food preference
            int temp;
            std::cin >> temp; // Read the type of food
            temp--; // Adjust the food type to be 0-indexed

            foods[temp]++; // Increment the count of this food type
        }
    }

    int ans = 0; // Initialize a counter for food types preferred by all people

    for (auto elem : foods) { // Loop through each food type count
        if (elem == n) { // Check if the food type is preferred by all people
            ans++; // Increment the counter
        }
    }

    std::cout << ans << std::endl; // Output the number of food types preferred by all people
}

