
package main

import (
    "fmt"
    "math/big"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the values of n, a, and b
    var n, a, b int
    fmt.Scan(&n, &a, &b)

    // Step 2: Create two slices to store the lists of integers
    list1 := make([]int, a)
    list2 := make([]int, b)

    // Step 3: Read the elements of list1 and list2 from the user
    for i := 0; i < a; i++ {
        fmt.Scan(&list1[i])
    }
    for i := 0; i < b; i++ {
        fmt.Scan(&list2[i])
    }

    // Step 4: Iterate through the range from 1 to n and print the appropriate list number
    for i := 0; i < n; i++ {
        if contains(list1, i+1) {
            fmt.Printf("%d ", 1)
        } else {
            fmt.Printf("%d ", 2)
        }
    }
}

// contains returns true if the given integer is present in the given slice
func contains(s []int, e int) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

// 