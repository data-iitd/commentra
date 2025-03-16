#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin >> n;
    cin >> k;
    long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Sort the array to facilitate the processing of elements
    sort(arr, arr + n);
    // Initialize a counter to keep track of valid elements
    int count = 0;
    // Iterate through the sorted array to apply the conditions
    for (int i = 0; i < n; i++) {
        // Check if the current element is not divisible by k
        if (arr[i] % k!= 0) {
            count++; // Increment count for valid element
        }
        // Check if the current element is divisible by k and its corresponding k-factor is not in the set
        else if (find(arr, arr + n, arr[i] / k) == NULL) {
            count++; // Increment count for valid element
        }
    }
    // Output the final count of valid elements
    cout << count << endl;
    return 0;
}
