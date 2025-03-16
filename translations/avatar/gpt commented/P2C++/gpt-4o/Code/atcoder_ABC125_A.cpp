#include <iostream>
using namespace std;

int main() {
    // Read input values for 'a', 'b', and 't' from the user
    int a, b, t;
    cin >> a >> b >> t;

    // Initialize the cookie count to zero
    int cookie = 0;

    // Set the initial time to 'a'
    double time = a;

    // Loop until the time exceeds 't + 0.5'
    while (time <= t + 0.5) {
        // Add 'b' cookies for each time interval
        cookie += b;
        // Increment the time by 'a' for the next iteration
        time += a;
    }

    // Print the total number of cookies collected
    cout << cookie << endl;

    return 0;
}

// <END-OF-CODE>
