
#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for dynamic memory allocation
#include <string.h> // Including the string library for string manipulation
#include <math.h> // Including the math library for mathematical functions
#include <time.h> // Including the time library for time-related functions
#include <assert.h> // Including the assert library for debugging

int main() {
    int N; // Declaring the variable N to store the number of elements
    scanf("%d", &N); // Reading the number of elements N from the input
    
    int* a = (int*)malloc(N * sizeof(int)); // Allocating memory for the array a with size N
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]); // Reading N elements and storing them in the array a
    }
    
    int* leftl = (int*)malloc(N * sizeof(int)); // Allocating memory for the array leftl with size N
    int* rightl = (int*)malloc(N * sizeof(int)); // Allocating memory for the array rightl with size N
    
    // Using a deque to find the nearest smaller element to the right
    int* que = (int*)malloc(N * sizeof(int)); // Allocating memory for the deque que with size N
    int index = 0;
    int front = 0;
    int rear = -1;
    while (index < N) {
        while (front <= rear && a[que[rear]] > a[index]) {
            int ind = que[rear--];
            rightl[ind] = index - ind - 1; // Calculating the distance
        }
        que[++rear] = index++; // Adding the current index to the deque
    }
    while (front <= rear) {
        int ind = que[front++];
        rightl[ind] = N - ind - 1; // Calculating the distance for remaining elements
    }
    
    // Using a deque to find the nearest smaller element to the left
    index = N - 1;
    front = 0;
    rear = -1;
    while (index >= 0) {
        while (front <= rear && a[que[rear]] > a[index]) {
            int ind = que[rear--];
            leftl[ind] = ind - index - 1; // Calculating the distance
        }
        que[++rear] = index--; // Adding the current index to the deque
    }
    while (front <= rear) {
        int ind = que[front++];
        leftl[ind] = ind - index - 1; // Calculating the distance for remaining elements
    }
    
    // Calculating the result by summing up the products
    long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (long) a[i] * (leftl[i] + 1) * (rightl[i] + 1); // Calculating the product and adding it to the result
    }
    
    // Printing the result
    printf("%ld\n", ans); // Printing the result
    
    free(a); // Freeing the memory allocated for the array a
    free(leftl); // Freeing the memory allocated for the array leftl
    free(rightl); // Freeing the memory allocated for the array rightl
    free(que); // Freeing the memory allocated for the deque que
    
    return 0; // Returning 0 to indicate successful execution
}

