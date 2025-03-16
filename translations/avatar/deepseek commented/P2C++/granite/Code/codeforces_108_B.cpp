

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s() {
    // Take input from the user
    int n;
    cin >> n;
    // Read the input, split it into a vector of integers, and store it in 'a'
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Sort the vector 'a'
    sort(a.begin(), a.end());
    // Iterate through the sorted vector starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            return "YES";
        }
    }
    // If the loop completes without finding a match, return 'NO'
    return "NO";
}

int main() {
    // Print the result returned by the function's()'
    cout << s() << endl;
    return 0;
}

