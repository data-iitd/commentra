#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define NUM (int) (1e5 + 2)

int main() {
    // Create a Scanner object for input
    int N;
    scanf("%d", &N);
    
    // Initialize a HashMap to store the index of each number
    int map[NUM];
    memset(map, -1, sizeof(map));
    
    // Initialize a PriorityQueue to store the numbers in sorted order
    int nums[NUM];
    int head = 0;
    int tail = 0;
    
    // Read N numbers from input
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp); // Read the next number
        nums[tail++] = tmp; // Add the number to the priority queue
        map[tmp] = i; // Store the index of the number in the HashMap
    }
    
    // Initialize variables to track the binary state and the difference count
    int bin = 0;
    int diff = 0;
    
    // Process the numbers in sorted order
    while (head < tail) {
        int num = nums[head++]; // Retrieve and remove the smallest number
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
    int ans = (diff / 2); 
    
    // Output the result
    printf("%d\n", ans); 
    
    return 0;
}

