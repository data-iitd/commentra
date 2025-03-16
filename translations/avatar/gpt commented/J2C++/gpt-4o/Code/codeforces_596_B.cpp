#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic array
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std;

int main() {
    // Reading the number of elements in the array
    int n;
    cin >> n;
    
    // Initializing a vector to hold the input values
    vector<long> arr(n);
    
    // Loop to read 'n' integers from the user and store them in the vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Initialize the answer with the absolute value of the first element
    long answer = abs(arr[0]);
    
    // Loop to calculate the sum of absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        answer += abs(arr[i] - arr[i - 1]);
    }
    
    // Output the final calculated answer
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
