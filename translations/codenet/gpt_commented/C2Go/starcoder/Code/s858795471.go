package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
    "strings"
)

// Function to search for a key in the array A of size n
func search(A []int, n int, key int) bool {
    i := 0 // Initialize index to 0
    A[n] = key // Sentinel value: place the key at the end of the array
    // Loop until the key is found in the array
    for A[i]!= key {
        i++ // Increment index until the key is found
    }
    // Return true if the key was found before the sentinel, false otherwise
    return i!= n
}

func main() {
    var n, q, key, sum int
    var A []int
    var i int

    // Read the number of elements in the array
    fmt.Scanf("%d", &n)
    // Read the elements of the array
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &A[i])
    }
    
    // Read the number of queries
    fmt.Scanf("%d", &q)
    // Process each query
    for i = 0; i < q; i++ {
        fmt.Scanf("%d", &key) // Read the key to search for
        // If the key is found in the array, increment the sum
        if search(A, n, key) {
            sum++
        }
    }
    
    // Output the total count of found keys
    fmt.Printf("%d\n", sum)
}

