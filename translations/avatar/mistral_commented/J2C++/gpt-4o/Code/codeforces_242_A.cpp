#include <iostream>
using namespace std;

int main() {
    // Create a variable to read input from the console
    int x, y, a, b;

    // Read four integers from the console
    cin >> x >> y >> a >> b;

    // Initialize a counter variable
    int count = 0;

    // Find the number of pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; ++j) {
            // If i is less than j, continue to the next iteration of the inner loop
            if (i <= j) continue;

            // Increment the counter if the condition is satisfied
            count++;
        }
    }

    // Print the result
    cout << count << endl;

    // Print all pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; ++j) {
            // If i is less than j, print the pair
            if (i <= j) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
