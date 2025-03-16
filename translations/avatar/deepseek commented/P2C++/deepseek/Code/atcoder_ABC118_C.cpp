#include <iostream>
#include <vector>
#include <numeric>  // Include the numeric library for the gcd function.
using namespace std;

int main() {
    int N;
    cin >> N;  // Read the integer input N.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];  // Read the space-separated integers and store them in the vector A.
    }
    int gcd = 0;
    for (int i = 0; i < N; ++i) {
        gcd = std::gcd(gcd, A[i]);  // Compute the GCD of all elements in the vector A using the gcd function from the numeric library.
    }
    cout << gcd << endl;  // Print the computed GCD.
    return 0;
}

