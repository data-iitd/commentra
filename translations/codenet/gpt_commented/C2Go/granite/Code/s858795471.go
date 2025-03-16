
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
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
    var err error

    // Read the number of elements in the array
    if n, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:]); err!= nil {
        panic(err)
    }
    // Read the elements of the array
    A = make([]int, n)
    for i := 0; i < n; i++ {
        if A[i], err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:]); err!= nil {
            panic(err)
        }
    }

    // Read the number of queries
    if q, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:]); err!= nil {
        panic(err)
    }
    // Process each query
    for i := 0; i < q; i++ {
        if key, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:]); err!= nil {
            panic(err)
        }
        // If the key is found in the array, increment the sum
        if search(A, n, key) {
            sum++
        }
    }

    // Output the total count of found keys
    fmt.Println(sum)
}

