#include <iostream>
using namespace std;

// Function to read an integer
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a map of integers
void MI(int &a, int &b, int &c) {
    cin >> a >> b >> c;
}

// Main function
int main() {
    const int mod = 1e9 + 7;  // Modulo value
    int N, A, B;  // Variables to hold N, A, and B
    MI(N, A, B);  // Reading N, A, and B
    long long ans = 0;  // Initializing the result variable
    
    // Calculating the number of complete cycles of A + B within N
    long long rep = N / (A + B);
    
    // Updating the result with the number of complete cycles multiplied by A
    ans += rep * A;
    
    // Calculating the remaining days after the complete cycles
    long long res = N - rep * (A + B);
    
    // Updating the result with the minimum of the remaining days and A
    ans += min(res, (long long)A);
    
    // Printing the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
