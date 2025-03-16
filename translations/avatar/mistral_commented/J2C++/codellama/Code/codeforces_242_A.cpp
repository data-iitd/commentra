
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int x, y, a, b;
    int count = 0;

    // Read four integers from the console
    cin >> x >> y >> a >> b;

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

    return 0;
}

