#include <iostream>
#include <vector>

using namespace std;

// Function to read the next integer from input
int nextInt() {
    int x;
    cin >> x; // Read an integer from standard input
    return x; // Return the integer value
}

// Function to read 'n' integers from input and return them as a vector
vector<int> nextInts(int n) {
    vector<int> vec(n); // Create a vector to hold 'n' integers
    for (int i = 0; i < n; i++) {
        vec[i] = nextInt(); // Fill the vector with integers from input
    }
    return vec; // Return the vector of integers
}

int main() {
    // Read two integers from input: n (number of elements) and k (some parameter)
    int n = nextInt();
    int k = nextInt();
    
    // Read 'n' integers into vector 'a'
    vector<int> a = nextInts(n);
    
    // Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0;

    // Initialize sum with the value of k and set ans to 1
    int sum = k;
    int ans = 1;
    
    // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while (sum < n) {
        sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
        ans++; // Increment the answer counter
    }
    
    // Print the final answer
    cout << ans << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
