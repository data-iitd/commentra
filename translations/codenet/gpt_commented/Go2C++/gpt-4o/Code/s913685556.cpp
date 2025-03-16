#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

int main() {
    // Read two integers from input
    int A, B;
    cin >> A >> B;

    // Calculate the maximum of A+B, A-B, and A*B
    int mx = max(A + B, A - B);
    mx = max(mx, A * B);

    // Print the maximum value
    cout << mx << endl;

    return 0;
}

// Scanner class is not needed in this simple case as we can use cin directly
// Additional functions for reading arrays or other types can be implemented if needed

// <END-OF-CODE>
