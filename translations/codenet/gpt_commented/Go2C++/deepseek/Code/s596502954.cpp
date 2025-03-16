#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to read the next integer from input
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read the next float from input
float nextFloat() {
    float f;
    cin >> f;
    return f;
}

// Function to read 'n' integers from input and return them as a vector
vector<int> nextInts(int n) {
    vector<int> slice(n);
    for (int i = 0; i < n; i++) {
        cin >> slice[i];
    }
    return slice;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    // Read two integers, sum them, and compare the result with a third integer
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    if (a + b >= c) {
        cout << "Yes\n"; // Print "Yes" if the sum is greater than or equal to the third integer
    } else {
        cout << "No\n"; // Print "No" otherwise
    }

    return 0;
}
