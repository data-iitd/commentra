

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Initializing scanner for reading input from stdin
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading the number of elements in the array
    int n;
    cin >> n;

    // Allocating memory for the array
    vector<int> ar(3 * n);

    // Reading elements of the array
    for (int i = 0; i < 3 * n; i++) {
        // Reading next integer and storing it in the array
        cin >> ar[i];
    }

    // Sorting the array in ascending order
    sort(ar.begin(), ar.end());

    // Calculating the sum of elements at index 3n-2i-1 in the sorted array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // Adding the element at index 3n-2i-1 to the sum
        sum += ar[3 * n - (i + 1) * 2];
    }

    // Printing the result
    cout << sum << endl;

    return 0;
}

