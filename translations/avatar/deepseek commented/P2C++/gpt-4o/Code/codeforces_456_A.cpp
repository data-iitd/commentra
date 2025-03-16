#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input representing the number of elements in the list `m`
    
    vector<vector<int>> m(n, vector<int>(2));  // Create a list of lists `m` where each sublist contains two integers
    for (int i = 0; i < n; ++i) {
        cin >> m[i][0] >> m[i][1];  // Input two integers for each sublist
    }
    
    // Sort the list `m` in descending order based on the second element of each sublist
    sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    
    vector<int> a = m[0];  // Assign the first element of the sorted list `m` to the variable `a`

    // Iterate over the rest of the elements in `m` starting from the second element
    for (size_t i = 1; i < m.size(); ++i) {
        if (m[i][1] > a[1]) {  // Check if the second element of the current element `i` is greater than the second element of the variable `a`
            cout << "Happy Alex" << endl;  // If true, print "Happy Alex" and break out of the loop
            break;
        }
        a = m[i];  // If false, assign the current element `i` to the variable `a`
    }
    // If the loop completes without breaking
    if (a == m.back()) {  // Check if we reached the last element without breaking
        cout << "Poor Alex" << endl;  // Print "Poor Alex"
    }

    return 0;
}

// <END-OF-CODE>
