#include <iostream>
#include <vector>

using namespace std;

bool possible(int N, vector<int>& A) {
    long long sum = 0; // Initialize sum to store the sum of the elements in the array A
    for (int i = 0; i < N; i++) sum += A[i]; // Calculate the sum of the elements in the array A
    long long NS = (long long)N * (N + 1) / 2; // Calculate the sum of the first N natural numbers (NS)
    if (sum % NS != 0) return false; // Check if the sum of the array A is divisible by NS. If not, return false
    long long K = sum / NS; // Calculate the value of K
    for (int i = 0; i < N; i++) {
        int j = (i == 0) ? N - 1 : i - 1; // Calculate the index of the previous element in the array A
        long long d = K - (A[i] - A[j]); // Calculate the difference
        if (d < 0 || d % N != 0) return false; // Check if the difference is negative or not divisible by N. If so, return false
    }
    return true; // If all elements satisfy the condition, return true
}

int main() {
    int N;
    cin >> N; // Read the number of elements N from the user
    vector<int> A(N); // Create a vector A to store the elements
    for (int i = 0; i < N; i++) cin >> A[i]; // Read N integers from the user and store them in the vector A
    if (possible(N, A)) { // Call the possible method to check if the array A can be rearranged to satisfy a certain condition
        cout << "YES" << endl; // Print "YES" if the condition is satisfied
    } else {
        cout << "NO" << endl; // Print "NO" if the condition is not satisfied
    }
    return 0;
}

// <END-OF-CODE>
