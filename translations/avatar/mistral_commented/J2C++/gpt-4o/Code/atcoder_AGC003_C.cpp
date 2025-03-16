#include <iostream> // Including the required header for input/output
#include <vector>   // Including the vector header
#include <queue>    // Including the priority queue header
#include <unordered_map> // Including the unordered_map header
using namespace std; // Using the standard namespace

int main() {
    const int NUM = 1e5 + 2; // Final static constant for the maximum size of the array
    int N; // Variable to store the number of elements in the array
    cin >> N; // Reading the number of elements

    unordered_map<int, int> map; // Creating an empty unordered_map to store the index of each unique element
    priority_queue<int, vector<int>, greater<int>> nums; // Creating a priority_queue to store the elements in ascending order

    // Reading the elements one by one and adding them to the priority_queue and unordered_map
    for (int i = 0; i < N; i++) {
        int tmp; // Temporary variable to store the input element
        cin >> tmp; // Reading an element
        nums.push(tmp); // Adding the element to the priority_queue
        map[tmp] = i; // Adding the index of the element to the unordered_map
    }

    int bin = 0; // Initializing a binary index variable
    int diff = 0; // Initializing a variable to store the difference in parity between elements

    // Processing the elements in the priority_queue
    while (!nums.empty()) {
        int num = nums.top(); // Getting the top element from the priority_queue
        nums.pop(); // Removing the top element from the priority_queue
        int idx = map[num]; // Getting the index of the element from the unordered_map

        // Checking if the binary index and the index of the current element have opposite parity
        if ((bin % 2) != (idx % 2)) {
            diff++; // Incrementing the difference if the condition is true
        }

        bin++; // Incrementing the binary index
        bin %= 2; // Setting the binary index to 0 or 1 based on the current parity
    }

    // Calculating and printing the answer
    int ans = diff / 2; // Calculating the answer
    cout << ans << endl; // Printing the answer

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
