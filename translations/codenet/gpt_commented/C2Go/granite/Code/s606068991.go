
package main

import "fmt"

// Function to print the array elements
func white(n int, A []int) {
    for i := 0; i < n-1; i++ {
        fmt.Printf("%d ", A[i]) // Print each element followed by a space
    }
    fmt.Printf("%d\n", A[i]) // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
func insertionsort(n int, A []int) {
    var i, j, a int
    for i = 0; i < n; i++ {
        for j = 0; j < i; j++ {
            if A[i] < A[j] {
                a = A[i]
                A[i] = A[j]
                A[j] = a // Swap the elements
            }
        }
        white(n, A) // Print the current state of the array after each insertion
    }
}

func main() {
    var i, n int
    var A []int // Declare variables for the number of elements and the array
    // Read the number of elements from user input
    fmt.Scan(&n)
    // Read the elements of the array from user input
    A = make([]int, n)
    for i = 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    // Call the insertion sort function to sort the array
    insertionsort(n, A)

    // 