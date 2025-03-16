#include <iostream>
#include <vector>

int main()
{
    # Declare variables for the number of people (n) and the number of food items (m)
    int n, m;
    std::cin >> n >> m; # Input the values of n and m

    # Create a vector to count the number of people who like each food item
    std::vector<int> foods(m);

    # Loop through each person to gather their food preferences
    for i in range(n):
        k = 0 # Number of food items the current person likes
        std::cin >> k # Input the number of food items

        # Loop through each food item liked by the current person
        for j in range(k):
            temp = 0 # Temporary variable to hold the food item index
            std::cin >> temp # Input the food item index
            temp -= 1 # Convert to zero-based index

            # Increment the count for the corresponding food item
            foods[temp] += 1

    # Initialize a counter for the number of food items liked by all people
    ans = 0
    # Loop through the food counts to find how many are liked by all n people
    for elem in foods:
        if elem == n: # Check if the food item is liked by all n people
            ans += 1 # Increment the answer if the condition is met

    # Output the total number of food items liked by all people
    std::cout << ans << std::endl

    # End of code
    