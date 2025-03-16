#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    // Take the number of rows as input
    int n;
    cin >> n;

    // Initialize an empty vector 's' to store the rows
    vector<vector<int>> s;

    // Read each row and append it to the vector 's'
    for (int i = 0; i < n; i++)
    {
        // Read a row as a string and convert it to a vector
        string k;
        cin >> k;
        vector<int> v;
        for (int j = 0; j < k.length(); j++)
        {
            v.push_back(k[j] - '0');
        }
        s.push_back(v);
    }

    // Initialize flags and empty vectors 'd1' and 'd2'
    bool flag = false;
    vector<int> d1;
    vector<int> d2;

    // Iterate through each element in the vector 's'
    for (int i = 0; i < n; i++)
    {
        // Iterate through each element in the same row and in the reverse order
        for (int j = 0; j < n; j++)
        {
            // If the current indices are same, append the element to 'd1'
            if (i == j)
            {
                d1.push_back(s[i][j]);
            }
            // If the current indices are reverse of each other, append the element to 'd2'
            if (i == n - j)
            {
                d2.push_back(s[i][j]);
            }
            // If the current indices are not same and not reverse, add the element to 'rem' set
            if (i != j && i != n - j)
            {
                set<int> rem;
                rem.insert(s[i][j]);
            }
        }
    }

    // Check if the size of 'rem' set is not equal to 1
    if (rem.size() != 1)
    {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }

    // Check if 'd1' and 'd2' vectors are equal
    if (d1 != d2)
    {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }

    // Check if all elements in 'd1' are same
    if (d1.size() != 1)
    {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }

    // Check if all elements in 'd1' are present in 'rem' set
    if (rem != d1)
    {
        // If the condition is true, print 'NO' and exit
        cout << "NO" << endl;
        return 0;
    }

    // If all the above conditions are false, print 'YES'
    cout << "YES" << endl;

    return 0;
}

