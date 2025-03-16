#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <sstream>  // For string stream
using namespace std;

int main() {
    // Reading two integers from user input: n and x
    int n, x;
    cin >> n >> x;

    // Calculating the maximum value based on n
    int max = n * 2 - 1;

    // Checking if x is equal to 1 or max, if so, print "No" and exit
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return 0; // Exit the program early
    }

    // If x is valid, print "Yes"
    cout << "Yes" << endl;

    // Prepare a string stream for formatting output
    stringstream ans;

    // Generate a sequence of numbers based on the input x and n
    for (int i = x + n - 1; i < x + n + max - 1; ++i) {
        ans << (i % max + 1) << endl; // Adjusting the number to fit within the range
    }

    // Print the generated sequence
    cout << ans.str();

    return 0;
}

// <END-OF-CODE>
