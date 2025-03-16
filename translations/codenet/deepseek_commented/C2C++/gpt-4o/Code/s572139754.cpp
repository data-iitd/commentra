#include <iostream>
using namespace std;

int main() {
    int n;
    // Read an integer from the user
    cin >> n;
    
    // Check if n is divisible by 1000
    if (n % 1000 == 0) 
        // If n is divisible by 1000, print 0
        cout << 0 << endl;
    else 
        // If n is not divisible by 1000, calculate the difference
        // between the next multiple of 1000 and n, and print that difference
        cout << (n / 1000 + 1) * 1000 - n << endl;

    return 0;
}

// <END-OF-CODE>
