package main

import "fmt"

func search(A []int, n int, key int) int {
    i := 0
    // Add the key to the end of the array to handle the case where the key is not found
    A = append(A, key)
    // Loop until the key is found in the array
    for A[i] != key {
        i++
    }
    // Return 1 if the key is found, otherwise return 0
    return i != n
}

func main() {
    var n, q, key, sum int
    var i int

    // Read the size of the array
    fmt.Scan(&n)
    // Read the array elements
    A := make([]int, n)
    for i = 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    // Read the number of queries
    fmt.Scan(&q)
    // Process each query
    for i = 0; i < q; i++ {
        fmt.Scan(&key)
        // Perform the search operation for the current query element
        if search(A, n, key) {
            sum++
        }
    }
    // Print the count of successful searches
    fmt.Println(sum)
}

