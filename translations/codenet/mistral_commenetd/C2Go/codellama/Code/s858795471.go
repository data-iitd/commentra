
package main

import "fmt"

// Function to search for a key in an array
func search(A []int, n int, key int) int {
    i := 0
    // Add the key to the end of the array
    A[n] = key
    // Search for the key in the array using a while loop
    for A[i] != key {
        i++
    }
    // Return 1 if the key was found before the end of the array, otherwise return 0
    if i != n {
        return 1
    } else {
        return 0
    }
}

func main() {
    var n int // Number of elements in the array
    var A [10000 + 1]int // Array to store the elements
    var q int // Number of queries
    var key int // Key to be searched for
    var sum int = 0 // Variable to store the number of keys found
    var i int // Loop counter

    // Read the number of elements in the array from the user
    fmt.Scan(&n)
    // Read the elements of the array from the user
    for i = 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    // Read the number of queries from the user
    fmt.Scan(&q)
    // For each query, search for the key in the array and if it is found, increment the sum
    for i = 0; i < q; i++ {
        fmt.Scan(&key) // Read the key to be searched for
        // Call the search function to find the key in the array
        if search(A, n, key) == 1 {
            sum++ // If the key is found, increment the sum
        }
    }
    // Print the number of keys found
    fmt.Println(sum)
}

