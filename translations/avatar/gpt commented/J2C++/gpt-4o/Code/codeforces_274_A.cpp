#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Create a variable to read the number of elements in the array
    int n;
    cin >> n;

    // Read the value of k
    long long k;
    cin >> k;

    // Initialize a vector to hold the input numbers
    vector<long long> arr(n);

    // Create a set to store unique elements that meet the criteria
    set<long long> uniqueElements;

    // Read n long integers into the vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array to facilitate the processing of elements
    sort(arr.begin(), arr.end());

    // Initialize a counter to keep track of valid elements
    int count = 0;

    // Iterate through the sorted array to apply the conditions
    for (int i = 0; i < n; i++) {
        // Check if the current element is not divisible by k
        if (arr[i] % k != 0) {
            count++; // Increment count for valid element
            uniqueElements.insert(arr[i]); // Add the element to the set
        }
        // Check if the current element is divisible by k and its corresponding k-factor is not in the set
        else if (uniqueElements.find(arr[i] / k) == uniqueElements.end()) {
            count++; // Increment count for valid element
            uniqueElements.insert(arr[i]); // Add the element to the set
        }
    }

    // Output the final count of valid elements
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
