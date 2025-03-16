#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Input the number of elements (n) and the position index (k)

    string v;
    cin >> v; // Input the string v

    vector<string> d = {"LEFT", "RIGHT"}; // Define a list containing the directions "LEFT" and "RIGHT"

    bool f = (k - 1 < n - k); // Determine the boolean value of f based on the comparison between k-1 and n-k

    int m = min(k - 1, n - k); // Assign m as the minimum of k-1 and n-k

    vector<string> a; // Initialize an empty list a to store the sequence of actions

    for (int i = 0; i < m; i++) {
        a.push_back(d[!f]); // Append the opposite direction to a based on the value of f
    }

    for (int i = (f ? v.size() - 1 : 0); (f ? i >= 0 : i < v.size()); (f ? i-- : i++)) {
        a.push_back("PRINT " + string(1, v[i])); // Append "PRINT" and the current character
        a.push_back(d[f]); // Append the direction f
    }

    for (size_t i = 0; i < a.size() - 1; i++) {
        cout << a[i] << endl; // Print all elements in a except the last one, separated by newlines
    }

    return 0;
}

// <END-OF-CODE>
