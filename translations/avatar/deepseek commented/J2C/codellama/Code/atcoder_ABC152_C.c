
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main ( ) {
    // Create a Scanner object to read input from the standard input stream
    int N;
    scanf("%d", &N);

    // Read the integer N from the input
    // int N = sc.nextInt ( ) ; 
    
    // Initialize an array of size N to store the integers
    int arr[MAX_SIZE];
    // Read N integers from the input and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        // arr [ i ] = sc.nextInt ( ) ; 
    }
    
    // Initialize a sum variable to 0
    int sum = 0;
    
    // Create a priority queue to store the integers in ascending order
    int q[MAX_SIZE];
    int front = -1;
    int rear = -1;
    
    // Iterate through the array and add each element to the priority queue
    for (int i = 0; i < N; i++) {
        rear++;
        q[rear] = arr[i];
        // q.add ( arr [ i ] ) ; 
        
        // Check if the current element is less than or equal to the smallest element in the priority queue
        if (arr[i] <= q[front]) {
            sum++;
        }
    }
    
    // Return the sum
    printf("%d", sum);
    // return sum ; 
}

