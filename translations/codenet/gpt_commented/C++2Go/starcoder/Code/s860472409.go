package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var N int
    var ans int
    var i int
    var count int

    // Read the number of elements in the array
    N, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))

    // Initialize an array of size N
    A := make([]int, N)

    // Input the elements into the array
    for i = 0; i < N; i++ {
        _, _ = fmt.Scanf("%d", &A[i])
    }

    // Initialize index and counters
    i = 0
    ans = 0    // To store the final answer
    count = 0  // To count consecutive equal elements

    // Loop through the array until the second last element
    for i < N - 1 {
        // Check if the current element is equal to the next element
        if A[i] == A[i + 1] {
            count++ // Increment count for consecutive elements
            
            // If count is odd, increment the answer
            if count % 2!= 0 {
                ans++
            }
        } else {
            // Reset count if elements are not equal
            count = 0
        }
        i++ // Move to the next element
    }

    // Output the final answer
    fmt.Printf("%d\n", ans)
}

