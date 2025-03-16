package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
    "sort" // Import the sort package for sorting functions
)

func main() {
    var n, a int // Declare variables to store the number of elements and the count of last elements to sum
    fmt.Scan(&n) // Read the value of n from standard input
    fmt.Scan(&a) // Read the value of a from standard input

    s := make([]int, n) // Create a slice to store the elements
    for i := 0; i < n; i++ { // Loop to read 'n' elements into the slice 's'
        fmt.Scan(&s[i]) // Read the elements from standard input
    }

    sort.Ints(s) // Sort the slice 's' in ascending order

    sum := 0 // Initialize a variable to store the sum of the last 'a' elements
    for i := n - 1; i > n - a - 1; i-- { // Loop to calculate the sum of the last 'a' elements
        sum += s[i] // Add the value of the current element to the sum
    }

    fmt.Println(sum) // Print the calculated sum to standard output
}

// <END-OF-CODE>
