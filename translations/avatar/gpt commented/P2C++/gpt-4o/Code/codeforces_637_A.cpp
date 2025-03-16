#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the input elements into a vector
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // Count the occurrences of each element using an unordered_map
    unordered_map<string, int> w;
    for (const auto& str : s) {
        w[str]++;
    }

    // Reverse the vector to process elements in reverse order
    reverse(s.begin(), s.end());

    // Initialize variables to track the index of the most frequent element and its value
    int c = -1;
    string a;

    // Iterate through each unique element in the count map
    for (const auto& pair : w) {
        const string& i = pair.first;
        // Check if the current element's count is equal to the maximum count
        if (pair.second == max_element(w.begin(), w.end(), 
            [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; })->second) {
            // If the index of the current element in the reversed vector is greater than the current index
            auto it = find(s.begin(), s.end(), i);
            int index = distance(s.begin(), it);
            if (index > c) {
                // Update the most frequent element and its index
                a = i;
                c = index;
            }
        }
    }

    // Print the most frequent element that appears last in the original order
    cout << a << endl;

    return 0;
}

// <END-OF-CODE>
