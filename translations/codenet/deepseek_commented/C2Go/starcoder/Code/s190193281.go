<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define constants for the maximum sizes of arrays S and T
const N = 1000000
const Q = 50000

// Declare variables
var n int
var S [N]int
var T [Q]int

// Function to perform binary search on array S
func binarySearch(key int) int {
    left := 0
    right := n
    mid := 0
    for left < right {
        mid = (left + right) / 2
        if S[mid] == key {
            return 1
        } else if key < S[mid] {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return 0
}

// Main function
func main() {
    var i, q, c int

    // Read the size of array S
    fmt.Scanf("%d", &n)
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &S[i])
    }

    // Read the size of array T
    fmt.Scanf("%d", &q)
    for i = 0; i < q; i++ {
        fmt.Scanf("%d", &T[i])
        if binarySearch(T[i]) == 1 {
            c++
        }
    }

    // Print the count of elements in T that are also in S
    fmt.Printf("%d\n", c)
}

