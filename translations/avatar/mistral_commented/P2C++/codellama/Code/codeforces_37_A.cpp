#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Take the number of elements in the list as input
    int n;
    cin >> n;

    // Initialize an empty vector 'l' to store the input elements
    vector<int> l;

    // Read the list elements from the standard input, convert them to integers and append to the vector
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }

    // Initialize variables 'high' and 'tower' with initial values
    int high = 1;
    int tower = n;

    // Iterate through the vector starting from the second element
    for (int i = 1; i < n; i++)
    {
        // If the current element is same as the previous one, decrement 'tower' and increment 'high'
        if (l[i] == l[i-1])
        {
            tower--;
            high++;
        }
        // If the current element is different, check if 'high' is greater than the current maximum and update it if true
        else
        {
            if (high > maximum)
            {
                maximum = high;
            }
            high = 1;
        }
    }

    // Check if the last 'high' value is greater than the current maximum and update it if true
    if (high > maximum)
    {
        maximum = high;
    }

    // Print the final result
    cout << maximum << " " << tower << endl;

    return 0;
}

