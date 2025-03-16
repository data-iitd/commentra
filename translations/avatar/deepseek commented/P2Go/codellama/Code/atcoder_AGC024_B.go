
package main

import (
    "fmt"
)

func main() {
    // Read the number of elements N
    var N int
    fmt.Scan(&N)
    // Read the list of integers P
    P := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&P[i])
    }
    // Call the editorial function with N and P as arguments
    editorial(N, P)
}

func editorial(N int, P []int) {
    // If there is only one element, print 0 and return
    if N == 1 {
        fmt.Println(0)
        return
    }
    // Initialize an array to store positions of elements in P
    a := make([]int, N+1)
    // Populate the array with positions of elements in P
    for i, p := range P {
        a[p] = i
    }
    // Initialize temporary and maximum length variables
    tmp := 1
    max_len := 1
    // Iterate through the positions to find the maximum length of consecutive increasing elements
    for i := 1; i < N; i++ {
        if a[i] < a[i+1] {
            tmp += 1
            max_len = max(max_len, tmp)
        } else {
            tmp = 1
        }
    }
    // Calculate the answer as N - max_len
    ans := N - max_len
    // Print the answer
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func WA(N int, P []int) {
    tmp := 0
    ans := 0
    for i, p := range P {
        if i == 0 || P[i-1]+1 == p {
            tmp += 1
        } else {
            ans = max(ans, tmp)
            tmp = 1
        }
    }
    fmt.Println(N - ans)
}

// 