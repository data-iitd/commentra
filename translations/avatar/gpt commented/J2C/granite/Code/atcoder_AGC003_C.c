
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <map>

int main() {
    // Define a constant for the maximum number of elements
    const int NUM = 100002; 

    // Read the number of elements
    int N; 
    scanf("%d", &N); 

    // Initialize a map to store the index of each number
    std::map<int, int> map; 

    // Initialize a priority queue to store the numbers in sorted order
    std::priority_queue<int> nums; 

    // Read N numbers from input
    for (int i = 0; i < N; i++) {
        int tmp; 
        scanf("%d", &tmp); // Read the next number
        nums.push(tmp); // Add the number to the priority queue
        map[tmp] = i; // Store the index of the number in the map
    }
    
    // Initialize variables to track the binary state and the difference count
    int bin = 0; 
    int diff = 0; 

    // Process the numbers in sorted order
    while (!nums.empty()) {
        int num = nums.top(); // Retrieve and remove the smallest number
        nums.pop(); 
        int idx = map[num]; // Get the original index of the number
        
        // Check if the parity of the current index and the binary state differ
        if ((bin % 2)!= (idx % 2)) {
            diff++; // Increment the difference count if they differ
        }
        
        // Update the binary state
        bin++; 
        bin %= 2; // Toggle between 0 and 1
    }
    
    // Calculate the final answer as half of the difference count
    int ans = diff / 2; 

    // Output the result
    printf("%d\n", ans); 

    return 0;
}
