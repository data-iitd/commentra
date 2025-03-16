#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic array

using namespace std;

int main() {
    // Reading the number of elements N from user input
    int N;
    cin >> N;
    
    // Initializing a vector A to store the input integers
    vector<int> A(N);
    
    // Loop to read N integers from user input and store them in vector A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Initializing a counter to keep track of the number of segments
    int count = 0;
    
    // Loop through the vector to identify segments of increasing or decreasing values
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

    return 0;
}

// <END-OF-CODE>
