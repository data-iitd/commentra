#include <iostream>
using namespace std;

// Function to read an integer
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers
void MI(int &a, int &b) {
    cin >> a >> b;
}

// Main function
int main() {
    // Setting the modulus value
    const int mod = 1e9 + 7;

    // Reading input values: N, A, and B
    int N, A, B;
    MI(N, A);
    B = I();

    // Initializing the answer variable to 0
    long long ans = 0;

    // Calculating the number of repetitions
    long long rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    long long res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, (long long)A);

    // Printing the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
