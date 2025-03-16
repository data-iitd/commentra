package main // Defining the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Defining the main function
    var n int // Declaring a variable n to hold the number of integers
    fmt.Scanln(&n) // Reading the first line of input containing the number of integers n

    result := 0 // Initializing the variable result to zero

    h := make([]int, n) // Creating a slice h of size n
    g := make([]int, n) // Creating a slice g of size n

    for i := 0; i < n; i++ { // Iterating through each index i from 0 to n-1
        fmt.Scan(&h[i], &g[i]) // Reading two integer values from the input and assigning them to the current index of slices h and g
    }

    for i := 0; i < n; i++ { // Iterating through each index i from 0 to n-1
        for j := 0; j < n; j++ { // Nested for loop iterating through each index j from 0 to n-1
            if h[i] == g[j] { // Checking if the current element of slice h is equal to the current element of slice g
                result++ // Incrementing the result variable if the condition is true
            }
        }
    }

    fmt.Println(result) // Printing the final result to the standard output
}

// <END-OF-CODE>
