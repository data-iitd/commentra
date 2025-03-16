#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w; // Taking input for k, n, and w

    if (1 <= k && w <= 1000) { // Checking if k and w are within the specified range
        long long total = 0; // Initializing total to 0
        for (int i = 1; i <= w; i++) { // Looping from 1 to w (inclusive)
            total += i * k; // Multiplying the current iteration number by k and adding to total
        }
        if (total > n) { // Checking if total is greater than n
            cout << total - n << endl; // Printing the difference between total and n if total is greater
        } else {
            cout << 0 << endl; // Printing 0 if total is not greater than n
        }
    }

    return 0;
}
// <END-OF-CODE>
