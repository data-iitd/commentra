
#include <iostream> // Including theiostream library for input/output operations
#include <queue> // Including the queue library for queue data structure
#include <vector> // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace for convenience

int main() {
    // Initialize cin for reading input
    int N; // Declaring an integer variable N to store the number of elements in the array
    cin >> N; // Reading the number of elements in the array

    vector<int> arr(N); // Creating a dynamic array of size N to store the elements

    // Using for loop to read and store elements in the array
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // Reading an integer and storing it in the array at the current index
    }

    int sum = 0; // Initializing sum variable to 0
    priority_queue<int> q; // Creating an empty priority_queue

    // Using for loop to iterate through the array
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

