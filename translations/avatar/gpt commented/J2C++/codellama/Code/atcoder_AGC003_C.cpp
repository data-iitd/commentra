
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// Define a constant for the maximum number of elements
const int NUM = (int) (1e5 + 2); 

int main() {
    // Create a Scanner object for input
    // Scanner sc = new Scanner(System.in); 
    int N;
    cin >> N;
    
    // Initialize a HashMap to store the index of each number
    map<int, int> map;
    
    // Initialize a PriorityQueue to store the numbers in sorted order
    priority_queue<int> nums;
    
    // Read N numbers from input
    for (int i = 0; i < N; i++) {
        int tmp; // Read the next number
        cin >> tmp;
        nums.push(tmp); // Add the number to the priority queue
        map[tmp] = i; // Store the index of the number in the HashMap
    }
    
    // Initialize variables to track the binary state and the difference count
    int bin = 0; 
    int diff = 0; 
    
    // Process the numbers in sorted order
    while (!nums.empty()) {
        int num = nums.top(); // Retrieve and remove the smallest number
        int idx = map[num]; // Get the original index of the number
        
        // Check if the parity of the current index and the binary state differ
        if ((bin % 2) != (idx % 2)) {
            diff++; // Increment the difference count if they differ
        }
        
        // Update the binary state
        bin++; 
        bin %= 2; // Toggle between 0 and 1
        nums.pop();
    }
    
    // Calculate the final answer as half of the difference count
    int ans = (diff / 2); 
    
    // Output the result
    cout << ans << endl;
    
    return 0;
}

