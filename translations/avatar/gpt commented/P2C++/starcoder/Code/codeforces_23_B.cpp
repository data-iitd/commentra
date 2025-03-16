#include <iostream>
using namespace std;

int main() {
    // Read an integer input from the user, which represents the number of test cases
    int n;
    cin >> n;
    
    // Loop through each test case
    for (int i = 0; i < n; i++) {
        // Read an integer input for the current test case
        int a;
        cin >> a;
        
        // Check if the input number is less than 2
        if (a < 2) {
            // If true, print 0 as the output for this case
            cout << 0 << endl;
        }
        
        // Check if the input number is greater than or equal to 2
        if (a >= 2) {
            // If true, print the result of (a - 2)
            cout << a - 2 << endl;
        }
    }
    
    return 0;
}
