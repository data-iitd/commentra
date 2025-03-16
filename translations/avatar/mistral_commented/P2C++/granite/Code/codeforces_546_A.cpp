

#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w; // Taking three integers as input from the user

    if (1 <= k && w <= 1000) { // Input validation
        int total = 0; // Initializing the variable 'total' to zero
        for (int i = 1; i <= w; i++) { // Iterating from 1 to w (inclusive)
            total += i * k; // Adding the product of k and the current index to the total variable
        }

        if (total > n) { // Checking if the total is greater than n or not
            cout << total - n; // If yes, printing the difference between total and n
        } else {
            cout << 0; // If no, printing zero
        }
    }

    return 0;
}

