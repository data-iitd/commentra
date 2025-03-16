#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;  // Read the integer k
    long long t = 0;  // Initialize t to 0

    for (int i = 1; i <= k; ++i) {  // Loop from 1 to k
        t = (t % k) * 10 + 7;  // Update t based on the current iteration
        if (t % k == 0) {  // Check if t is divisible by k
            cout << i << endl;  // Print the current index if t is divisible by k
            return 0;  // Exit the program as we found the solution
        }
    }
    
    cout << -1 << endl;  // Print -1 indicating no solution was found
    return 0;
}

// <END-OF-CODE>
