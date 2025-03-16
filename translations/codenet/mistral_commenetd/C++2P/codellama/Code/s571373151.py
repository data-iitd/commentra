#include <iostream>
#include <vector>

int main()
{
    # Declare variables
    int n, m;
    std::vector<int> foods(m);

    # Read input values
    std::cin >> n >> m;

    # Initialize a vector of size m to store the count of each food item
    std::vector<int> foods(m);

    # Read n food preferences from the standard input
    for i in range(n):
        k = int(input())

        # Read the indices of the food items in the current preference
        for j in range(k):
            temp = int(input())

            # Increment the count of the corresponding food item in the foods vector
            foods[temp] += 1

    # Initialize a variable to store the number of food items that appear in all preferences
    ans = 0

    # Iterate through each element in the foods vector and check if its count is equal to the total number of preferences
    for elem in foods:
        if elem == n:
            ans += 1

    # Print the value of ans to the standard output
    print(ans)
}

