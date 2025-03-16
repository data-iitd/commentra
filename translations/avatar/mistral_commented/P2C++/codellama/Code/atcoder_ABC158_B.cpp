#include <iostream>
#include <cmath>

using namespace std;

// Custom input function
int input() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers
int* MI() {
    int* arr = new int[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = input();
    }
    return arr;
}

// Function to read a list of integers
int* LI() {
    int n = input();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = input();
    }
    return arr;
}

// Main function
int main() {
    // Setting the modulus value
    int mod = 1000000007;

    // Reading input values: N, A, and B
    int* arr = MI();
    int N = arr[0], A = arr[1], B = arr[2];

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    cout << ans << endl;

    // Deallocating memory
    delete[] arr;

    return 0;
}

// END-OF-CODE
