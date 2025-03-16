#include <iostream> // Including iostream for input and output
#include <queue>    // Including queue for using priority_queue
#include <vector>   // Including vector for using dynamic arrays

using namespace std; // Using the standard namespace

// Function to find the solution
int solve() {
    int N; // Variable to store the number of elements
    cin >> N; // Reading the number of elements in the array

    vector<int> arr(N); // Creating a vector of size N

    // Using a for loop to read and store elements in the vector
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Reading an integer and storing it in the vector at the current index
    }

    int sum = 0; // Initializing sum variable to 0
    priority_queue<int, vector<int>, greater<int>> q; // Creating an empty min-heap priority queue

    // Using a for loop to iterate through the vector
    for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]); // Adding the current element to the queue

        // Checking if the current element is smaller than or equal to the top element of the queue
        if (arr[i] <= q.top()) {
            sum++; // Incrementing sum if the condition is true
        }
    }

    // Returning the sum as the solution
    return sum;
}

// Main function is the entry point of the C++ application
int main() {
    cout << solve() << endl; // Calling solve function to get the solution and print it
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
