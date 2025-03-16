#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i]; // Read the list of integers
    }

    sort(l.begin(), l.end()); // Sort the list l to prepare for binary search operations

    long long ans = 0; // Initialize the answer variable to store the count of valid triangles

    for (int i = 0; i < n; ++i) { // Outer loop: iterate over each element in l
        for (int j = i + 1; j < n; ++j) { // Inner loop: iterate over each element in l starting from i+1
            int a = l[i];
            int b = l[j]; // a and b are the sides of the triangle being considered
            
            int right = lower_bound(l.begin(), l.end(), a + b) - l.begin(); // Find the leftmost index where a + b can be inserted
            int left = upper_bound(l.begin(), l.end(), max(a - b, b - a)) - l.begin(); // Find the rightmost index where max(a - b, b - a) can be inserted
            
            int tmp = max(0, right - left); // Calculate the number of valid elements that can form a triangle
            
            if (left <= i && i < right) {
                tmp--; // Adjust for overcounting if i is within the valid range
            }
            if (left <= j && j < right) {
                tmp--; // Adjust for overcounting if j is within the valid range
            }
            
            ans += tmp; // Add the valid triangle count for the current pair to the total answer
        }
    }

    cout << ans / 3 << endl; // Print the final answer, dividing by 3 as implied by the context

    return 0;
}
// <END-OF-CODE>
