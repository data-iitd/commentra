

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main(int argc, char **argv) {
    // Create a map to store the counts of integers
    int N, M;
    scanf("%d %d", &N, &M);
    int *m = (int *)malloc(sizeof(int) * 100001);
    memset(m, 0, sizeof(int) * 100001);
    
    // Read N integers and store their counts in the map
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        m[a]++;
    }
    
    // Perform M operations to update the map with new integers and their counts
    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        m[C] += B;
    }
    
    // Create a slice of integers from the map keys
    int *ints = (int *)malloc(sizeof(int) * 100001);
    int int_size = 0;
    for (int i = 0; i < 100001; i++) {
        if (m[i] > 0) {
            ints[int_size++] = i;
        }
    }
    
    // Sort the slice of integers in descending order
    qsort(ints, int_size, sizeof(int), cmpfunc);
    
    // Initialize variables to keep track of the remaining elements and the sum
    int rest = N;
    int sum = 0;
    
    // Iterate through the sorted integers and calculate the sum based on the conditions
    for (int i = 0; i < int_size; i++) {
        int num = m[ints[i]];
        if (num >= rest) {
            sum += rest * ints[i];
            break;
        }
        sum += num * ints[i];
        rest -= num;
    }
    
    // Print the calculated sum
    printf("%d\n", sum);
    
    // Free memory
    free(m);
    free(ints);
    
    return 0;
}

// Helper function to compare two integers for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

