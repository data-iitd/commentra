#include <iostream>
using namespace std;

int main() {
    int a, b, t;
    cin >> a >> b >> t; // Taking three inputs from the user: a, b, and t
    int cookie = 0; // Initializing the cookie count to 0
    double time = a; // Setting the initial time to the value of a

    while (time <= t + 0.5) { // The loop continues as long as time is less than or equal to t + 0.5
        cookie += b; // Incrementing the cookie count by b
        time += a; // Incrementing the time by a
    }

    cout << cookie << endl; // Printing the final cookie count after the loop finishes
    return 0;
}
// <END-OF-CODE>
