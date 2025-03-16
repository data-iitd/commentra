#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

const int NUM = 1e5 + 2; // Define a constant for the maximum number of elements

int main() {
    // Create a Scanner object for input
    int N;
    cin >> N; // Read the number of elements

    // Initialize an unordered_map to store the index of each number
    unordered_map<int, int> map;

    // Initialize a priority_queue to store the numbers in sorted order
    priority_queue<int, vector<int>, greater<int>> nums;

    // Read N numbers from input
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp; // Read the next number
        nums.push(tmp); // Add the number to the priority queue
        map[tmp] = i; // Store the index of the number in the unordered_map
    }

    // Initialize variables to track the binary state and the difference count
    int bin = 0;
    int diff = 0;

    // Process the numbers in sorted order
    while (!nums.empty()) {
        int num = nums.top(); // Retrieve the smallest number
        nums.pop(); // Remove the smallest number
        int idx = map[num]; // Get the original index of the number

        // Check if the parity of the current index and the binary state differ
        if ((bin % 2) != (idx % 2)) {
            diff++; // Increment the difference count if they differ
        }

        // Update the binary state
        bin++;
        bin %= 2; // Toggle between 0 and 1
    }

    // Calculate the final answer as half of the difference count
    int ans = diff / 2;

    // Output the result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
