#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Read an input line (not used in the logic)
    string line;
    getline(cin, line);
    
    // Read a line of integers, split by spaces, and convert them to a vector of integers
    vector<int> a;
    string s;
    while (getline(cin, s, ' '))
    {
        a.push_back(stoi(s));
    }
    
    // Sort the vector of integers in ascending order
    sort(a.begin(), a.end());
    
    // Iterate through the sorted vector starting from the second element
    for (int i = 1; i < a.size(); i++)
    {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2)
        {
            // If the condition is met, print 'YES' and return 0
            cout << "YES" << endl;
            return 0;
        }
    }
    
    // If no such pair is found, print 'NO' and return 0
    cout << "NO" << endl;
    return 0;
}

// 