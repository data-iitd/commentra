#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Take an integer 'n' as input from the user
    int n;
    cin >> n;

    // Initialize a counter 'c' to 0
    int c = 0;

    // Iterate through the range of 'n'
    for (int i = 0; i < n; i++)
    {
        // Take 'n' lists of integers as input from the user
        vector<int> l1;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            l1.push_back(x);
        }

        // Check if the sum of the elements in the current list is greater than 1
        if (sum(l1.begin(), l1.end()) > 1)
        {
            // Increment the counter 'c' by 1 if the condition is true
            c++;
        }
    }

    // Print the value of the counter 'c'
    cout << c << endl;

    return 0;
}

