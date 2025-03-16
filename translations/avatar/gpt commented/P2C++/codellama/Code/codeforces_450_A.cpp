#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i, ind;
    vector<int> l, l2;

    // Read two integers n and m from input, where n is the number of elements and m is the divisor
    cin >> n >> m;

    // Read a list of n integers from input
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }

    // Initialize an empty list to store the results after processing the input list
    l2.clear();

    // Iterate through each element in the input list
    for (i = 0; i < n; i++)
    {
        // If the current element is divisible by m, append the quotient to l2
        if (l[i] % m == 0)
            l2.push_back(l[i] / m);
        // If the current element is not divisible by m, append the quotient plus one to l2
        else
            l2.push_back((l[i] / m) + 1);
    }

    // Find the maximum value in the processed list l2
    int mx = *max_element(l2.begin(), l2.end());

    // Iterate through the range of n to find the index of the maximum value in l2
    for (i = 0; i < n; i++)
    {
        if (l2[i] == mx)
        {
            ind = i; // Store the index of the maximum value
            break;
        }
    }

    // Print the index of the maximum value (1-based index)
    cout << ind + 1 << endl;

    return 0;
}

