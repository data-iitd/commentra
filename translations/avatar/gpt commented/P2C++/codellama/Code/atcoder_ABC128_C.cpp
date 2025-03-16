#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    // Reading the values of n and m from input
    int n, m;
    cin >> n >> m;
    
    // Reading m lists of integers, each containing values after the first element
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        li[i].push_back(x);
        for (int j = 1; j < n; j++)
        {
            cin >> x;
            li[i].push_back(x);
        }
    }
    
    // Reading a tuple p from input
    vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    
    // Creating a set q that contains all unique elements from the lists in li
    set<int> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q.insert(li[i][j]);
        }
    }
    
    // Creating a set r that contains all integers from 1 to n
    set<int> r;
    for (int i = 1; i <= n; i++)
    {
        r.insert(i);
    }
    
    // Finding the set of values v that are in r but not in q
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.begin()));
    
    // Initializing the answer variable to count valid combinations
    int ans = 0;
    
    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i <= q.size(); i++)
    {
        // Generating combinations of size i from the set q
        vector<int> s(i);
        for (int j = 0; j < i; j++)
        {
            s[j] = *(q.begin() + j);
        }
        do
        {
            // Checking each list in li against the corresponding value in p
            for (int u = 0; u < m; u++)
            {
                set<int> t(s.begin(), s.end());  // Converting the combination to a set for intersection
                // If the count of common elements is odd and does not match w, break
                if (t.size() != 0 && t.size() % 2 != p[u])
                {
                    break;
                }
            }
            // If all checks passed, increment the answer by 2 raised to the power of the size of v
            if (s.size() == i)
            {
                ans += pow(2, v.size());
            }
        } while (next_combination(s.begin(), s.end(), q.end()));
    }
    
    // Printing the final answer
    cout << ans << endl;
    
    return 0;
}

// END-OF-CODE
