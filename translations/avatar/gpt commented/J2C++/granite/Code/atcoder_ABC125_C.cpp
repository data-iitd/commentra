
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the GCD of two integers using the Euclidean algorithm
int gcd(int a, int b) {
    int tmp;
    
    // Ensure a is greater than or equal to b
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    // If b is zero, return a as the GCD
    if (b == 0) {
        return a;
    }
    
    // Calculate GCD using the Euclidean algorithm
    int r = -1;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r!= 0);
    
    // Return the GCD
    return a;
}

int main() {
    // Read the number of elements
    int N;
    cin >> N;
    
    // Initialize the array A with size N
    vector<int> A(N);
    
    // Read N integers from input and store them in array A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Arrays to hold the GCD values from the left and right
    vector<int> M(N); // Not used in the code, can be removed
    vector<int> L(N); // GCD values from the left
    vector<int> R(N); // GCD values from the right
    
    // Initialize the first element of L with the first element of A
    L[0] = A[0];
    
    // Calculate GCD from the left side
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }
    
    // Initialize the last element of R with the last element of A
    R[N - 1] = A[N - 1];
    
    // Calculate GCD from the right side
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }
    
    // Calculate the maximum GCD excluding the last element
    int answer = max(L[N - 2], R[1]);
    
    // Iterate through the array to find the maximum GCD excluding the current element
    for (int i = 1; i < N - 1; i++) {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }
    
    // Print the final answer
    cout << answer << endl;
    
    // End of code
    return 0;
}

