
package main

import "fmt"

// Function to print the array elements
func white(n int, A []int) {
    for i := 0; i < n-1; i++ {
        fmt.Printf("%d ", A[i])
    }
    fmt.Printf("%d\n", A[i])
}

// Function to perform insertion sort on the array
func insertionsort(n int, A []int) {
    var i, j, a int
    for i = 0; i < n; i++ {
        for j = 0; j < i; j++ {
            if A[i] < A[j] {
                // Swap A[i] and A[j]
                a = A[i]
                A[i] = A[j]
                A[j] = a
            }
        }
        // Print the array after each insertion
        white(n, A)
    }
}

// Main function to handle input and call the sorting function
func main() {
    var n int
    fmt.Scan(&n)
    A := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    insertionsort(n, A)
}

