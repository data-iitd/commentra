#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // Read two integers n and d from input
    int n, d;
    cin >> n >> d;

    // Initialize an empty list to store the elements
    vector<int> x;
    // Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
    int m = 0, q = 0;

    // Read the elements of the list from input and split them into individual strings
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, ' '))
    {
        x.push_back(stoi(temp));
    }

    // Iterate through the list to compare adjacent elements
    for (int a = 0; a < x.size() - 1; a++)
    {
        // Check if the current element is greater than or equal to the next element
        if (x[a] >= x[a + 1])
        {
            // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
            q = (x[a] - x[a + 1]) / d + 1;
            // Update the total adjustments made
            m = m + q;
            // Adjust the next element by adding the necessary increments of d
            x[a + 1] = x[a + 1] + q * d;
        }
    }

    // Print the total number of adjustments made
    cout << m << endl;

    return 0;
}

