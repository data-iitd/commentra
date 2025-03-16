#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the array
    vector<int> v(100010); // Initialize the array to store the values
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Read the values into the array
    }

    vector<int> vo(100010, 0); // Initialize arrays to count odd and even numbers
    vector<int> ve(100010, 0);
    vector<int> vt(100010, 0);

    for (int i = 0; i < n; i++) {
        vt[v[i]]++; // Count all numbers
        if (i % 2 == 0) {
            ve[v[i]]++; // Count even numbers
        } else {
            vo[v[i]]++; // Count odd numbers
        }
    }

    sort(vo.rbegin(), vo.rend()); // Sort the count arrays in descending order
    sort(ve.rbegin(), ve.rend());
    sort(vt.rbegin(), vt.rend());

    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) { // Check if the maximum counts are consecutive
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]); // Calculate the minimum difference
    } else {
        ans = n - vo[0] - ve[0]; // Calculate the difference if not consecutive
    }

    cout << ans << endl; // Print the result
    return 0; // End of the program
}

// <END-OF-CODE>
