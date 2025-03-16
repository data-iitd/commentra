#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int limit;
} work;

int compare(const void *a, const void *b) {
    return ((work *)a)->limit - ((work *)b)->limit;
}

int main() {
    // Read the number of works
    int n;
    scanf("%d", &n);
    
    // Create an array of work structs with a length of n
<<<<<<< HEAD
    work *ws = (work *)malloc(n * sizeof(work));
=======
    work *ws = malloc(n * sizeof(work));
>>>>>>> 98c87cb78a (data updated)
    
    // Read the time and limit for each work and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ws[i].time, &ws[i].limit);
    }
    
    // Sort the array of works based on the limit field
    qsort(ws, n, sizeof(work), compare);
    
    // Initialize a sum variable to keep track of the cumulative time
    long long sum = 0;
    
    // Iterate over the sorted array of works, adding the time of each work to the sum
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        
        // Check if the cumulative time exceeds the limit of the current work
        if (sum > ws[i].limit) {
            printf("No\n");
            free(ws);
            return 0;
        }
    }
    
    // If the loop completes without the sum exceeding any limit, print "Yes"
    printf("Yes\n");
    
    // Free the allocated memory
    free(ws);
    
    return 0;
}

// <END-OF-CODE>
