#include <iostream> // Including the iostream library for input and output
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std;

int main() {
    // Creating a variable to store the number of test cases
    int q;
    cin >> q; // Reading the number of test cases
    
    // Looping through each test case
    while (q-- > 0) {
        // Reading the integer n for the current test case
        int n;
        cin >> n;
        
        // Initializing a variable to store the result
        long long s = 0;
        
        // Calculating the highest power of 2 less than or equal to n
        int x = (int) (log(n) / log(2));
        x++;
        
        // Calculating the final result using the derived formula
        s = -1 * (long long) pow(2, x) + 2 + ((long long) n * (long long) (n + 1)) / 2 - (long long) pow(2, x);
        
        // Printing the result for the current test case
        cout << s << endl;
    }
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
