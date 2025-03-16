
#include <iostream> // Importing the standard input/output stream objects
#include <map> // Importing the map container
#include <algorithm> // Importing the algorithm library

using namespace std; // Using the standard namespace

int main() {
    int n; // Declaring an integer variable n to store the number of elements
    cin >> n; // Reading the integer n from the input

    map<int, int> m; // Initializing a map to store the frequency of numbers

    // Looping n times to read n numbers
    while (n-- > 0) {
        int num; // Declaring an integer variable num to store the current number
        cin >> num; // Reading the next integer from the input

        // Checking if there is no key less than the current number
        if (m.lower_bound(num) == m.begin()) {
            // Incrementing the frequency of the current number
            m[num]++; // Incrementing the frequency in the map
        } else {
            // Finding the largest key less than the current number
            auto it = prev(m.lower_bound(num));
            // Decrementing the frequency of the found key and removing it if frequency becomes zero
            if (--it->second == 0) {
                m.erase(it); // Erasing the key-value pair from the map
            }
            // Incrementing the frequency of the current number
            m[num]++; // Incrementing the frequency in the map
        }
    }

    // Calculating the sum of all frequencies in the map
    int ans = 0;
    for (auto it = m.begin(); it!= m.end(); it++) {
        ans += it->second; // Adding the frequency to the sum
    }

    // Printing the sum of frequencies
    cout << ans << endl; // Printing the sum of frequencies

    return 0; // Returning 0 to indicate successful execution
}

