#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take input dimensions and threshold from user
    int n, m, x;
    cin >> n >> m >> x;

    // Initialize 2D array 'c' with dimensions (n, m)
    int c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }

    // Initialize empty lists 'l' for storing combinations and'rem' for storing indices
    vector<vector<int>> l;
    vector<int> rem;

    // Initialize variable 'ans' for storing minimum number of tests
    int ans = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= m; i++)
    {
        // Generate all combinations of 'pre' indices of size 'i'
        for (auto j : itertools::combinations(pre, i))
        {
            // Append the combination to list 'l'
            l.push_back(vector<int>(j.begin(), j.end()));
        }
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 1; i <= m; i++)
    {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each index 'j' in current combination
        for (int j : l[i])
        {
            // Add the test result at index 'j' and test case 'i' to 'ca'
            ca += c[j][i];
        }

        // If the sum of tests in current combination is less than threshold 'x',
        // add the index of the current combination to'rem' list
        if (ca < x)
        {
            rem.insert(rem.begin(), i);
        }
        // If the sum of tests in current combination is greater than or equal to threshold 'x',
        // continue to next combination
        else
        {
            continue;
        }

        // If'rem' list is not empty, remove the combinations with indices in'rem' from 'l' list
        if (rem.size() > 0)
        {
            for (int j : rem)
            {
                l.erase(l.begin() + j - 1);
            }
            rem.clear();
        }

        // If 'l' list is empty, print -1 and break the loop
        if (l.size() == 0)
        {
            cout << -1 << endl;
            break;
        }
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    else
    {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each valid combination and calculate the sum of tests
        for (auto i : l)
        {
            ca = 0;
            for (int j : i)
            {
                ca += c[j][0];
            }

            // Update 'ans' with minimum number of tests among all valid combinations
            if (ans == 0)
            {
                ans = ca;
            }
            else
            {
                ans = min(ans, ca);
        }

        // Print the minimum number of tests required
        cout << ans << endl;
    }

    return 0;
}

