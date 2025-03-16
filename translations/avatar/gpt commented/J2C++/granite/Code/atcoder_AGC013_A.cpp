
#include <iostream> // Include the necessary header file for input/output operations

using namespace std; // Using the standard namespace for input/output operations

int main() {
    // Creating a Scanner object to read input from the user
    // Scanner stdIn(cin); // Not needed in C++
    
    // Reading the number of elements N from user input
    int N;
    cin >> N;
    
    // Initializing an array A of size N to store the input integers
    int A[N];
    
    // Loop to read N integers from user input and store them in array A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Initializing a counter to keep track of the number of segments
    int count = 0;
    
    // Loop through the array to identify segments of increasing or decreasing values
    for (int i = 0; i < N; i++) {
        // If we are at the last element, increment the count
        if (i == N - 1) {
            count++;
        } 
        // If the current element is equal to the next element, do nothing
        else if (A[i] == A[i + 1]) {
            // No action needed, just continue
        } 
        // If the current element is less than the next element, find the end of the increasing segment
        else if (A[i] < A[i + 1]) {
            while (A[i] <= A[i + 1]) {
                i++; // Move to the next element
                // Break if we reach the end of the array
                if (i == N - 1) break;
            }
            // Increment the count for the found segment
            count++;
        } 
        // If the current element is greater than the next element, find the end of the decreasing segment
        else {
            while (A[i] >= A[i + 1]) {
                i++; // Move to the next element
                // Break if we reach the end of the array
                if (i == N - 1) break;
            }
            // Increment the count for the found segment
            count++;
        }
    }
    
    // Output the total number of segments found
    cout << count << endl;
    
    // End of the code
    return 0;
}
