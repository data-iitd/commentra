package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var (
        n   int
        ans int
    )

    // Read the size of the vector
    fmt.Scanf("%d\n", &n)

    // Initialize a vector of size n
    p := make([]int, n)

    // Read the elements of the vector
    for i := 0; i < n; i++ {
        fmt.Scanf("%d\n", &p[i])
    }

    ans = 0

    // Loop through the vector to check for specific conditions
    for i := 0; i < n-1; i++ {
        // Check if the current element matches its expected position (1-based index)
        if p[i] == i+1 {
            p[i+1] = p[i] // Set the next element to the current element
            ans += 1 // Increment the answer counter
        }
    }

    // Check if the last element matches its expected position
    if p[n-1] == n {
        ans += 1 // Increment the answer counter if the condition is met
    }

    fmt.Println(ans)
}

