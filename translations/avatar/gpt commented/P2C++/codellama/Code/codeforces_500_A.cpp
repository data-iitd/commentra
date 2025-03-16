
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Read the number of cells (n) and the target cell (t) from input
    int n, t;
    cin >> n >> t;

    // Read the list of jumps for each cell
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    // Initialize the current cell position
    int current_cell = 0;

    // Loop until the current cell exceeds the target cell
    while (current_cell <= t)
    {
        // Move to the next cell based on the jump value from the current cell
        current_cell += s[current_cell - 1];

        // Check if the current cell is exactly the target cell
        if (current_cell == t)
        {
            cout << "YES" << endl;  // Print "YES" if the target cell is reached
            return 0;               // Exit the program
        }
        else
        {
            continue;  // Continue the loop if the target cell is not reached
        }
    }

    // If the loop ends without reaching the target cell, print "NO"
    cout << "NO" << endl;

    return 0;
}

