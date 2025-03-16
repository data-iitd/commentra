#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to apply the logic to the vector
vector<int> func(vector<int>& A) {
    vector<int> a = A; // Create a copy of the vector to modify it
    int min = 0;

    // Iterate through the vector and apply the logic to each integer
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it
            a.erase(a.begin() + i);
            i--; // Decrease the index to account for the removed element
        } else {
            if (min != 0) { // If there is already a minimum value
                a[i] = a[i] % min; // Apply the modulo operation
                if (a[i] == 1) { // If the result is 1, print 1 and exit
                    cout << 1 << endl;
                    exit(0);
                }
            } else { // If there is no minimum value yet
                min = a[i]; // Assign the current integer as the minimum value
            }
        }
    }

    // Sort the vector in ascending order and return it
    sort(a.begin(), a.end());
    return a;
}

int main() {
    int n;
    cin >> n; // Read the first integer from the input

    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        int singleValue;
        cin >> singleValue; // Read the only integer
        cout << singleValue << endl; // Print the only integer
        return 0; // Exit the program
    }

    // Initialize a vector to store the integers
    vector<int> a(n);

    // Read the rest of the integers and add them to the vector
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the vector in ascending order
    sort(a.begin(), a.end());

    // Check if the last integer in the vector is 0, if so, print 0 and exit the program
    if (a.back() == 0) {
        cout << 0 << endl; // Print 0
        return 0; // Exit the program
    }

    // Initialize the answer variable
    int ans = 0;

    // Use a while loop to keep applying the function to the vector until it contains only one element
    while (true) {
        if (a.size() == 1) {
            ans = a[0]; // Assign the only remaining integer to the answer variable
            break; // Exit the loop
        }
        a = func(a); // Apply the function to the vector and assign the result back to it
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
