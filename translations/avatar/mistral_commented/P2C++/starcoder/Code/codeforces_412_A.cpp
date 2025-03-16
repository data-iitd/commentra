#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements `n` and the number of queries `k` from the standard input
    int n, k;
    cin >> n >> k;

    // Read a single string `v` from the standard input
    string v;
    cin >> v;

    // Initialize a list `d` with two elements: "LEFT" and "RIGHT"
    vector<string> d = {"LEFT", "RIGHT"};

    // Determine the direction based on the difference between `k` and `n-k`
    bool f = k - 1 < n - k;

    // Determine the number of elements to be appended to the list `a`
    int m = min(k - 1, n - k);

    // Initialize an empty list `a`
    vector<string> a;

    // Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
    for (int i = 0; i < m; i++) {
        a.push_back(d[not f]);
    }

    // Iterate through the string `v` with a step of 2 times the value of `f`
    for (int i = 0; i < v.size(); i += 2 * f) {
        // Append "PRINT <character>" and the corresponding direction to the list `a`
        a.push_back("PRINT " + v[i]);
        a.push_back(d[f]);
    }

    // Print all the elements of the list `a`, except the last one, separated by newline characters
    for (int i = 0; i < a.size() - 1; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
