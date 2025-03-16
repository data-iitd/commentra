#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Taking an integer input from the user
    int i = 1, j = n * n;  // Initializing variables i and j

    // Starting a while loop that continues as long as i is less than j
    while (i < j) {
        cout << i << " " << j << endl;  // Printing the current values of i and j
        i += 1;  // Incrementing i by 1
        j -= 1;  // Decrementing j by 1
    }

    return 0;
}

