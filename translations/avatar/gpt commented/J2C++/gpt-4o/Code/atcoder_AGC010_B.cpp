#include <iostream>
#include <vector>

using namespace std;

bool possible(int N, vector<int>& A) {
    // Calculate the sum of all elements in the array A
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    
    // Calculate the expected sum NS based on the formula for the sum of the first N natural numbers
    long long NS = (long long)N * (N + 1) / 2;
    
    // Check if the total sum is divisible by NS; if not, return false
    if (sum % NS != 0) {
        return false;
    }
    
    // Calculate the value of K which is the target average
    long long K = sum / NS;
    
    // Verify the condition for each element in the array
    for (int i = 0; i < N; i++) {
        // Determine the previous index in a circular manner
        int j = (i == 0) ? N - 1 : i - 1;
        
        // Calculate the difference d needed to satisfy the condition
        long long d = K - (A[i] - A[j]);
        
        // If d is negative or not divisible by N, return false
        if (d < 0 || d % N != 0) {
            return false;
        }
    }
    
    // If all conditions are satisfied, return true
    return true;
}

int main() {
    // Create a variable to read input from the user
    int N;
    
    // Read the number of elements N
    cin >> N;
    
    // Initialize a vector A to hold N integers
    vector<int> A(N);
    
    // Populate the vector A with N integers from user input
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Check if it is possible to achieve the desired condition with the array A
    if (possible(N, A)) {
        // If possible, print "YES"
        cout << "YES" << endl;
    } else {
        // If not possible, print "NO"
        cout << "NO" << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
