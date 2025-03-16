
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Function prototype for linear search
func linersearch(a []int, n int, key int) bool {
    i := 0

    // Sentinel value: place the key at the end of the array
    a[n] = key

    // Search for the key in the array
    for a[i]!= key {
        i++ // Increment index until the key is found
    }

    // Return true if the key was found within the original array bounds
    return i!= n
}

func main() {
    var n, q, t, count int
    var s []int

    // Read the number of elements in the array
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

    // Read n elements into the array s
    s = make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &s[i])
    }

    // Read the number of queries
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &q)

    // Process each query to check if the element exists in the array
    for i := 0; i < q; i++ {
        // Read the query element
        fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &t)

        // Use linear search to check if the element t is in the array s
        if linersearch(s, n, t) {
            count++ // Increment count if found
        }
    }

    // Output the total count of found elements
    fmt.Println(count)
}

// 