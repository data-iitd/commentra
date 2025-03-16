

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function to apply the logic to the vector
vector<int> func(vector<int> a) {
    int min = 0;

    // Iterate through the vector and apply the logic to each integer
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            a.erase(a.begin() + i);
            i--;
        } else {
            if (min!= 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min;
                if (a[i] == 1) { // If the result is 1, print 1 and exit the program
                    cout << 1 << endl;
                    exit(0);
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a[i];
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
        int x;
        cin >> x; // Read the only integer
        cout << x << endl; // Print the only integer
        return 0;
    }

    vector<int> a(n); // Initialize a vector to store the integers

    // Read the rest of the integers and add them to the vector
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the vector in ascending order
    sort(a.begin(), a.end());

    // Check if the last integer in the vector is 0, if so, print 0 and exit the program
    if (a[n - 1] == 0) {
        cout << 0 << endl; // Print 0
        return 0;
    }

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
    cout << ans << endl; // Print the answer

    return 0;
}

