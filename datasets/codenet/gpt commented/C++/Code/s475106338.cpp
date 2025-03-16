#include <iostream>
using namespace std;

int main(void) {
    // Declare variables for input
    int i, t, n;

    // Loop to process 4 test cases
    for(i = 0; i < 4; i++) {
        // Read the type (t) and quantity (n) from input
        cin >> t >> n;

        // Calculate and output the result based on the type (t)
        if(t == 1) {
            // If type is 1, multiply n by 6000
            cout << 6000 * n << endl;
        }
        else if(t == 2) {
            // If type is 2, multiply n by 4000
            cout << 4000 * n << endl;
        }
        else if(t == 3) {
            // If type is 3, multiply n by 3000
            cout << 3000 * n << endl;
        }
        else if(t == 4) {
            // If type is 4, multiply n by 2000
            cout << 2000 * n << endl;
        }
    }
}
