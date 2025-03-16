

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // Read two integers n and m from input
    vector<int> l(n);  // Initialize a vector of size n to store the list of integers
    for (int i = 0; i < n; i++) {
        cin >> l[i];  // Read a list of integers
    }
    vector<int> l2;  // Initialize an empty vector to store the results
    for (int i = 0; i < n; i++) {
        if (l[i] % m == 0) {  // Check if the element is divisible by m
            l2.push_back(l[i] / m);  // Append the quotient to l2
        } else {
            l2.push_back(l[i] / m + 1);  // Append the quotient plus one to l2
        }
    }
    int mx = *max_element(l2.begin(), l2.end());  // Find the maximum value in l2
    int ind = distance(l2.begin(), max_element(l2.begin(), l2.end()));  // Find the index of the maximum value
    cout << ind + 1 << endl;  // Print the index of the maximum value plus one
    return 0;
}

