#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements N
    int N;
    scanf("%d", &N);
    
    // Initialize an array A to hold N integers
    int* A = (int*) malloc(N * sizeof(int));
    
    // Populate the array A with N integers from user input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Check if it is possible to achieve the desired condition with the array A
    if (possible(N, A)) {
        // If possible, print "YES"
        printf("YES");
    } else {
        // If not possible, print "NO"
        printf("NO");
    }
    
    // 