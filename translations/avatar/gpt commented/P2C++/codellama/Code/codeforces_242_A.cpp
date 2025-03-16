#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Read input values for x, y, a, and b and convert them to integers
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    // Initialize an empty vector to store valid game pairs
    vector<pair<int, int>> games;

    // Iterate over the range from a to x (inclusive)
    for (int i = a; i <= x; i++)
    {
        // Skip the iteration if i is less than or equal to b
        if (i <= b)
        {
            continue;
        }
        else
        {
            // Iterate over the range from b to y (inclusive)
            for (int j = b; j <= y; j++)
            {
                // Check if the current i is greater than j
                if (i > j)
                {
                    // If the condition is met, append the pair (i, j) to the games vector
                    games.push_back(make_pair(i, j));
                }
            }
        }
    }

    // Print the total number of valid game pairs found
    cout << games.size() << endl;

    // Print each valid game pair
    for (int i = 0; i < games.size(); i++)
    {
        cout << games[i].first << " " << games[i].second << endl;
    }

    return 0;
}

