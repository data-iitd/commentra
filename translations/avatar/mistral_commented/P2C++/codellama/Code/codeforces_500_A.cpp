#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declaring and initializing the variables
    int n, t, current_cell = 0;
    vector<int> s;

    // Taking input for number of test cases and time limit
    cin >> n >> t;

    // Taking input for the jumps
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }

    // Main logic of the program starts here
    while (current_cell <= t)
    {
        // Incrementing the current cell position by the jump from the previous cell
        current_cell += s[current_cell - 1];

        // Checking if the current cell position is equal to the target position
        if (current_cell == t)
        {
            // If yes, then print "YES" and exit the program
            cout << "YES" << endl;
            return 0;
        }

        // If not, then continue to the next iteration
        else
        {
            continue;
        }
    }

    // If the loop terminates without finding the target position, then print "NO"
    cout << "NO" << endl;

    return 0;
}

