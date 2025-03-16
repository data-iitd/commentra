#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void print(int x, int n) {
    // Calculating the maximum value based on n
    int max = n * 2 - 1;
    
    // Checking if x is equal to 1 or max, if so, print "No" and exit the method
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return; // Exit the method early
    }
    
    // If x is valid, print "Yes"
    cout << "Yes" << endl;
    
    // Prepare the line separator for formatting output
    string sep = "\n";
    
    // Generate a sequence of numbers based on the input x and n
    string ans = accumulate(next(x + n - 1), next(x + n + max - 1), stringstream(), [&](stringstream ss, int e) {
        // Adjusting the number to fit within the range
        return ss << (e % max + 1) << sep;
    }).str();
    
    // Print the generated sequence
    cout << ans << endl;
}

int main() {
    // Creating a Scanner object to read input from the user
    int n, x;
    cin >> n >> x;
    
    // Calling the print method with the inputs x and n
    print(x, n);
    
    return 0;
}

