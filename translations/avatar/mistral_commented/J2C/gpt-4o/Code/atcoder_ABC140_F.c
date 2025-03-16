#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Initialize variables
    int N;
    scanf("%d", &N);
    
    // Calculate the size of the array S based on N
    int size = 1 << N;
    
    // Initialize the array S with user input
    int *S = (int *)malloc(size * sizeof(int));
    // Initialize a boolean array spawned to keep track of which slimes have been spawned
    bool *spawned = (bool *)malloc(size * sizeof(bool));
    // Set the last element of spawned to true
    spawned[size - 1] = true;

    // Read the initial positions of slimes from user input and store them in array S
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }
    
    // Sort the array S in ascending order
    qsort(S, size, sizeof(int), compare);

    // Initialize an array to store the indices of the currently active slimes
    int *active = (int *)malloc(size * sizeof(int));
    int active_count = 0;
    // Set the last element of spawned to true and add its index to the active list
    active[active_count++] = size - 1;

    // Iterate through each generation of slimes
    for (int i = 0; i < N; i++) {
        // Sort the active array in descending order
        for (int j = 0; j < active_count - 1; j++) {
            for (int k = j + 1; k < active_count; k++) {
                if (active[j] < active[k]) {
                    int temp = active[j];
                    active[j] = active[k];
                    active[k] = temp;
                }
            }
        }

        // Initialize an array to store the indices of the slimes that will be activated in the next generation
        int *activated = (int *)malloc(size * sizeof(int));
        int activated_count = 0;
        // Initialize a variable named next to keep track of the index of the current slime in array S
        int next = size - 1;

        // Iterate through each slime in the current generation
        for (int j = 0; j < active_count; j++) {
            int slime = active[j];
            // While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            // If the current index next is less than 0, print "No" and exit the program
            if (next < 0) {
                printf("No\n");
                free(S);
                free(spawned);
                free(active);
                free(activated);
                return 0;
            }
            // Set the current index as spawned and add its index to the activated array
            spawned[next] = true;
            activated[activated_count++] = S[next];
        }
        // Add all the indices of the activated slimes to the active array
        for (int j = 0; j < activated_count; j++) {
            active[active_count++] = activated[j];
        }
        free(activated);
    }

    // Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
    printf("Yes\n");

    // Free allocated memory
    free(S);
    free(spawned);
    free(active);

    return 0;
}
