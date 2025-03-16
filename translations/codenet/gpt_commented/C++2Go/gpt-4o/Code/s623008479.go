package main

import (
    "fmt"
    "sort"
)

func main() {
    var n, k int // Declare variables for the number of elements and the number of largest elements to sum
    fmt.Scan(&n, &k) // Read the values of n and k from standard input

    l := make([]int, n) // Create a slice of size n to store the elements
    for i := 0; i < n; i++ {
        fmt.Scan(&l[i]) // Read each element into the slice
    }

    sort.Ints(l) // Sort the slice in ascending order

    ans := 0 // Initialize a variable to hold the sum of the largest k elements
    for i := 0; i < k; i++ {
        ans += l[n-1-i] // Add the largest k elements to ans
    }

    fmt.Println(ans) // Output the result
}

// <END-OF-CODE>
