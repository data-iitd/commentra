
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    // (Note: This part is not possible in C, so we assume the input is provided as command-line arguments)
    
    // Read the integer N which determines the size of the input array
    int N = atoi(argv[1]);
    
    // Calculate the size of the array as 2^N
    int size = 1 << N;
    
    // Initialize an array S to hold the input values
    int S[size];
    
    // Initialize a boolean array to track which elements have been spawned
    int spawned[size];
    
    // Mark the last element as spawned (the largest element)
    spawned[size - 1] = 1;
    
    // Read N elements into the array S
    for (int i = 0; i < size; i++) {
        S[i] = atoi(argv[i + 2]);
    }
    
    // Sort the array S in ascending order
    qsort(S, size, sizeof(int), cmpfunc);
    
    // Create a list to keep track of active slimes
    int active[size];
    int active_size = 1;
    active[0] = S[size - 1];
    
    // Mark the largest element as spawned
    spawned[size - 1] = 1;
    
    // Iterate N times to activate new slimes
    for (int i = 0; i < N; i++) {
        // Sort the active list in descending order
        qsort(active, active_size, sizeof(int), cmpfunc);
        
        // Create a list to keep track of newly activated slimes
        int activated[size];
        int activated_size = 0;
        
        // Initialize the next index to the last element of S
        int next = size - 1;
        
        // Iterate through each slime in the active list
        for (int j = 0; j < active_size; j++) {
            // Find the next unspawned element that is less than the current slime
            while (next >= 0 && (S[next] >= active[j] || spawned[next])) {
                next--;
            }
            
            // If no valid unspawned element is found, print "No" and exit
            if (next < 0) {
                printf("No\n");
                return 0;
            }
            
            // Mark the found element as spawned
            spawned[next] = 1;
            
            // Add the newly activated slime to the activated list
            activated[activated_size++] = S[next];
        }
        
        // Add all newly activated slimes to the active list
        for (int j = 0; j < activated_size; j++) {
            active[active_size++] = activated[j];
        }
    }
    
    // If all iterations complete successfully, print "Yes"
    printf("Yes\n");
    
    return 0;
}

