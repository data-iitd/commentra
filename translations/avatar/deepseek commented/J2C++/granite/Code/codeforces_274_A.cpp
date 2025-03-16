
#include <iostream> // Step 1: Include necessary headers
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k; // Step 2: Declare variables
    cin >> n >> k; // Step 3: Read input values
    long long arr[n]; // Step 3: Read input values
    set<long long> st; // Step 3: Read input values

    for (int i = 0; i < n; i++) { // Step 4: Read array elements
        cin >> arr[i];
    }

    sort(arr, arr + n); // Step 5: Sort the array

    int count = 0; // Step 6: Initialize count variable

    for (int i = 0; i < n; i++) { // Step 7: Iterate through the array
        if (arr[i] % k!= 0) { // Check if the element is not divisible by k
            count++; // Increment the count
            st.insert(arr[i]); // Add the element to the set
        } else if (st.find(arr[i] / k) == st.end()) { // Check if the quotient is not in the set
            count++; // Increment the count
            st.insert(arr[i]); // Add the element to the set
        }
    }

    cout << count << endl; // Step 8: Print the result

    return 0;
}
