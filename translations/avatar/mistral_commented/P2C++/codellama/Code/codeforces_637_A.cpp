#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // Read the number of strings to be processed
    int n;
    cin >> n;

    // Read the strings and split the last string by space
    vector<string> s;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.push_back(temp);
    }

    // Create a Counter object to store the occurrences of each string
    map<string, int> w;

    // Initialize variables for storing the index of the longest string and its value
    int c = -1, a = 0;

    // Iterate through each string in the Counter object
    for (int i = 0; i < s.size(); i++)
    {
        // If the current string has the maximum occurrences
        if (w[s[i]] == max(w.begin(), w.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; }))
        {
            // If its index in the original list is greater than the current index of the longest string
            if (i > c)
            {
                // Update the longest string and its index
                a = s[i];
                c = i;
            }
        }
    }

    // Print the longest string
    cout << a << endl;

    return 0;
}

