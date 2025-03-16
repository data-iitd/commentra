#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the integer N which determines the size of the input array
    int N;
    scanf("%d", &N);
    
    // Calculate the size of the array as 2^N
    int size = 1 << N;
    
    // Initialize an array S to hold the input values
    int *S = (int *)malloc(size * sizeof(int));
    
    // Initialize a boolean array to track which elements have been spawned
    bool *spawned = (bool *)malloc(size * sizeof(bool));
    
    // Mark the last element as spawned (the largest element)
    spawned[size - 1] = true;
    
    // Read N elements into the array S
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }
    
    // Sort the array S in ascending order
    qsort(S, size, sizeof(int), compare);
    
    // Create a list to keep track of active slimes
    int *active = (int *)malloc(size * sizeof(int));
    int active_count = 0;
    
    // Add the largest element to the active list
    active[active_count++] = S[size - 1];
    
    // Mark the largest element as spawned
    spawned[size - 1] = true;
    
    // Iterate N times to activate new slimes
    for (int i = 0; i < N; i++) {
        // Sort the active list in descending order
        for (int j = 0; j < active_count - 1; j++) {
            for (int k = j + 1; k < active_count; k++) {
                if (active[j] < active[k]) {
                    int temp = active[j];
                    active[j] = active[k];
                    active[k] = temp;
                }
            }
        }
        
        // Create a list to keep track of newly activated slimes
        int *activated = (int *)malloc(size * sizeof(int));
        int activated_count = 0;
        
        // Initialize the next index to the last element of S
        int next = size - 1;
        
        // Iterate through each slime in the active list
        for (int j = 0; j < active_count; j++) {
            int slime = active[j];
            
            // Find the next unspawned element that is less than the current slime
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            
            // If no valid unspawned element is found, print "No" and exit
            if (next < 0) {
                printf("No\n");
                free(S);
                free(spawned);
                free(active);
                free(activated);
                return 0;
            }
            
            // Mark the found element as spawned
            spawned[next] = true;
            
            // Add the newly activated slime to the activated list
            activated[activated_count++] = S[next];
        }
        
        // Add all newly activated slimes to the active list
        for (int j = 0; j < activated_count; j++) {
            active[active_count++] = activated[j];
        }
        
        free(activated);
    }
    
    // If all iterations complete successfully, print "Yes"
    printf("Yes\n");
    
    // Free allocated memory
    free(S);
    free(spawned);
    free(active);
    
    return 0;
}
