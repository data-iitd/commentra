#include <iostream>
using namespace std;

int main() {
    // Declare integer variables n and k to store input values
    int n, k;
    
    // Read two integers from standard input and store them in n and k
    cin >> n >> k;

    // Check if k is less than or equal to half of n, considering n's parity
    if (k <= (n + n % 2) / 2) {
        // If true, print "YES"
        cout << "YES" << endl;
    } else {
        // If false, print "NO"
        cout << "NO" << endl;
    }

    return 0;
}
