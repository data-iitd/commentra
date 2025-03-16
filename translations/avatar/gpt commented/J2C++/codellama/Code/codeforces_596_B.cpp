#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    cin >> n;
    
    // Initializing an array to hold the input values
    long arr[n];
    
    // Loop to read 'n' integers from the user and store them in the array
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

