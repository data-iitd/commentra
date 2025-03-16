package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var N int // Declare an integer variable N
    fmt.Scan(&N) // Read an integer value from standard input and store it in N

    A := make([]int, N) // Declare a slice A of size N
    for i := 0; i < N; i++ {
        fmt.Scan(&A[i]) // Read N integers from standard input and store them in the slice A
    }

    m := A[0] // Initialize the variable m to the first element of the slice A
    M := A[0] // Initialize the variable M to the first element of the slice A
    for i := 0; i < N; i++ { // Start a loop that iterates through the slice A
        if A[i] < m {
            m = A[i] // If the current element is less than m, update m to the current element
        }
        if A[i] > M {
            M = A[i] // If the current element is greater than M, update M to the current element
        }
    }

    fmt.Println(M - m) // Print the difference between the maximum and minimum values in the slice A
}

// <END-OF-CODE>
