#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to read an integer list from standard input
vector<int> readIntList() {
    int n;
    cin >> n;
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    return result;
}

// Main function
int main() {
    // Read input values
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Calculate the maximum product of pairs of numbers
    int result = max({a * c, b * d, a * d, b * c});

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
