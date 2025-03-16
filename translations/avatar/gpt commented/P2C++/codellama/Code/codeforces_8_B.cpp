#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Read the input string representing movements
    string record_of_movements;
    cin >> record_of_movements;

    // Initialize the starting coordinates (x, y) at (0, 0)
    int x = 0, y = 0;

    // Define the movement directions: Left (L), Right (R), Up (U), Down (D)
    map<char, pair<int, int>> d_movement = {
        {'L', make_pair(0, -1)},
        {'R', make_pair(0, 1)},
        {'U', make_pair(1, 0)},
        {'D', make_pair(-1, 0)}
    };

    // Create a dictionary to track visited coordinates, starting with the initial position
    map<pair<int, int>, char> d;
    d[make_pair(x, y)] = '';

    // Initialize a flag to detect if a bug occurs
    bool bug = false;

    // Iterate through each movement in the input string
    for (char move : record_of_movements)
    {
        // Store the current position before the move
        pair<int, int> temp = make_pair(x, y);

        // Update the coordinates based on the movement direction
        x += d_movement[move].first;
        y += d_movement[move].second;

        // Check if the new position has already been visited
        if (d.find(make_pair(x, y)) == d.end())
        {
            // If not visited, check for potential bugs by looking at all movement directions
            for (auto step : d_movement)
            {
                // Check if moving in any direction from the new position leads to a visited position
                if (make_pair(x + d_movement[step].first, y + d_movement[step].second) != temp &&
                    d.find(make_pair(x + d_movement[step].first, y + d_movement[step].second)) != d.end())
                {
                    // If a bug is detected, set the flag and break the loop
                    bug = true;
                    break;
                }
            }
        }
        else
        {
            // If the new position was already visited, set the bug flag
            bug = true;
        }

        // If a bug has been detected, exit the loop
        if (bug)
        {
            break;
        }

        // Mark the new position as visited
        d[make_pair(x, y)] = '';
    }

    // After processing all movements, check if a bug was detected
    if (bug)
    {
        // Print 'BUG' if a bug was found
        cout << "BUG" << endl;
    }
    else
    {
        // Print 'OK' if no bugs were found
        cout << "OK" << endl;
    }

    return 0;
}

