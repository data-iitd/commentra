#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve() {
    // Read the number of elements in the array
    int N;
    cin >> N;
    
    // Initialize an array to hold the input values
    vector<int> arr(N);
    
    // Populate the array with user input
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Initialize a variable to keep track of the count of elements
    int sum = 0;
    
    // Create a priority queue to manage the elements
    priority_queue<int> q;
    
    // Iterate through the array to process each element
    for (int i = 0; i < arr.size(); i++) {
        // Add the current element to the priority queue
        q.push(arr[i]);
        
        // Check if the current element is less than or equal to the smallest element in the queue
        if (arr[i] <= q.top()) {
            // Increment the count if the condition is met
            sum++;
        }
    }
    
    // Return the final count of elements that met the condition
    return sum;
}

