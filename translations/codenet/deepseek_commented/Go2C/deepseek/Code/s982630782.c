#include <stdio.h>
#include <stdlib.h>

// Helper function to read an integer from stdin
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Helper function to read an integer from stdin
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int main() {
    // Create a map to store the counts of integers
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Create an array to store the counts of integers
    int *counts = (int *)calloc(100001, sizeof(int));
    
    // Read N integers and store their counts in the array
    for (int i = 0; i < N; i++) {
        int num = readInt();
        counts[num]++;
    }
    
    // Perform M operations to update the array with new integers and their counts
    for (int i = 0; i < M; i++) {
        int B = readInt();
        int C = readInt();
        counts[C] += B;
    }
    
    // Create a temporary array to store the counts of integers
    int *temp = (int *)calloc(100001, sizeof(int));
    for (int i = 0; i < 100001; i++) {
        temp[i] = counts[i];
    }
    
    // Sort the array of counts in descending order
    for (int i = 0; i < 100000; i++) {
        for (int j = i + 1; j < 100001; j++) {
            if (temp[i] < temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    
    // Initialize variables to keep track of the remaining elements and the sum
    int rest = N;
    long long sum = 0;
    
    // Iterate through the sorted counts and calculate the sum based on the conditions
    for (int i = 0; i < 100001; i++) {
        int num = temp[i];
        if (num >= rest) {
            sum += rest * i;
            break;
        }
        sum += num * i;
        rest -= num;
    }
    
    // Print the calculated sum
    printf("%lld\n", sum);
    
    // Free the allocated memory
    free(counts);
    free(temp);
    
    return 0;
}
