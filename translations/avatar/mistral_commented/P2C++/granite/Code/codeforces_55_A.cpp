

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Read an integer from the user

    while (n % 2 == 0) {  // While n is even
        n /= 2;  // Divide n by 2 to remove the last even factor
    }

    if (n == 1) {  // If n is now 1
        cout << "YES" << endl;  // Print 'YES'
    } else {  // Otherwise
        cout << "NO" << endl;  // Print 'NO'
    }

    return 0;
}

