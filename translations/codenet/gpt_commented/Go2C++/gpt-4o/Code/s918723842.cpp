#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

int main() {
    // Read three integers from input: H, W, and N
    int H, W, N;
    cin >> H >> W >> N;

    // Calculate the maximum of H and W
    int A = max(H, W);

    // Calculate and print the number of full groups needed to accommodate N items
    cout << (N + A - 1) / A << endl;

    return 0;
}

// Scanner class is not needed in this simple case as we can use cin directly
// <END-OF-CODE>
