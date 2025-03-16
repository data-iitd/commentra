package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function, the entry point of the program
    var n int64  // Declare a variable to store the number of elements

    fmt.Scan(&n)  // Read the value of n from the standard input
    a := make([]int64, n)  // Declare a slice `a` with size n
    count := make([]int64, n)  // Declare a slice `count` with size n

    for i := int64(1); i < n; i++ {  // Loop to read n-1 values into the slice `a`
        fmt.Scan(&a[i])
    }

    for i := int64(0); i < n; i++ {  // Loop to initialize the `count` slice to zero
        count[i] = 0
    }

    for i := int64(1); i < n; i++ {  // Loop to increment the `count` slice based on the values in `a`
        count[a[i]-1]++
    }

    for i := int64(0); i < n; i++ {  // Loop to print the values in the `count` slice
        fmt.Println(count[i])
    }
}

// <END-OF-CODE>
