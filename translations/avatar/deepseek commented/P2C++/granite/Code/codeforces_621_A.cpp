

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements in the list
    vector<int> lst(n);  // Create a vector to store the list of integers
    for (int i = 0; i < n; i++) {
        cin >> lst[i];  // Read the list of integers
    }
    sort(lst.begin(), lst.end());  // Sort the list in ascending order
    reverse(lst.begin(), lst.end());  // Reverse the list to get descending order

    int od = 0;  // Initialize a counter for odd numbers
    for (int i = 0; i < n; i++) {
        if (lst[i] & 1) {  // Check if the number is odd
            od++;
        }
    }

    int sum = 0;  // Initialize sum to accumulate the result
    bool ok = false;  // Initialize a flag to track if an odd number has been added

    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {  // Check if the number is even
            sum += lst[i];  // Add even numbers to sum
        } else {
            if (ok || od > 1) {  // Check if an odd number can be added
                sum += lst[i];  // Add odd number to sum
                od--;  // Decrement the count of odd numbers
                ok =!ok;  // Toggle the flag
            }
        }
    }

    cout << sum << endl;  // Print the final sum

    return 0;
}
