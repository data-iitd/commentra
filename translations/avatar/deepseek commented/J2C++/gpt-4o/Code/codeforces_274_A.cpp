#include <iostream> // Step 1: Include necessary headers
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n; // Step 2: Declare variable for number of elements
    long long k; // Step 2: Declare variable for k
    cin >> n >> k; // Step 3: Read input values
    vector<long long> arr(n); // Step 3: Create a vector for array elements
    set<long long> s; // Step 3: Create a set to store unique elements

    for (int i = 0; i < n; i++) { // Step 4: Read array elements
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // Step 5: Sort the array

    int count = 0; // Step 6: Initialize count variable

    for (int i = 0; i < n; i++) { // Step 7: Iterate through the array
        if (arr[i] % k != 0) { // Check if the element is not divisible by k
            count++; // Increment the count
            s.insert(arr[i]); // Add the element to the set
        } else if (s.find(arr[i] / k) == s.end()) { // Check if the quotient is not in the set
            count++; // Increment the count
            s.insert(arr[i]); // Add the element to the set
        }
    }

    cout << count << endl; // Step 8: Print the result
    return 0; // End of main function
}

// <END-OF-CODE>
