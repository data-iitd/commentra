#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the number of strings to be processed
    int n;
    cin >> n;

    // Read the strings and split the last string by space
    string s;
    cin >> s;
    vector<string> v;
    while (s!= "") {
        v.push_back(s);
        cin >> s;
    }

    // Create a Counter object to store the occurrences of each string
    map<string, int> w;
    for (int i = 0; i < v.size(); i++) {
        w[v[i]]++;
    }

    // Initialize variables for storing the index of the longest string and its value
    int c = -1, a = 0;

    // Iterate through each string in the Counter object
    for (auto i : w) {
        // If the current string has the maximum occurrences
        if (w[i.first] == max(w.values())) {
            // If its index in the original list is greater than the current index of the longest string
            if (v.index(i.first) > c) {
                // Update the longest string and its index
                a = i.first;
                c = v.index(i.first);
            }
        }
    }

    // Print the longest string
    cout << a << endl;

    return 0;
}

