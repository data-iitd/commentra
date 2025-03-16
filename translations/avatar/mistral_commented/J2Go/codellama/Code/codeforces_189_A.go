
package main

import (
    "fmt"
    "math"
)

func main() {
    var n int // Defining the number of elements in the array
    fmt.Scan(&n) // Reading the number of elements in the array from the console
    maxn := 4010 // Defining the maximum size of the dynamic programming array

    // Defining an array to store the array elements
    var a, b, c int
    fmt.Scan(&a, &b, &c) // Reading the three integers representing the array elements
    arr := []int{a, b, c}

    // Creating a dynamic programming array of size maxn
    dp := make([]int, maxn)

    // Initializing the dynamic programming array with minimum values
    for i := 0; i < n; i++ {
        dp[i] = math.MinInt32 // Setting all elements to minimum value
    }

    dp[0] = 0 // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for i := 0; i < 3; i++ { // Looping through the array elements
        for j := arr[i]; j < len(dp); j++ { // Looping through the dynamic programming array
            dp[j] = int(math.Max(float64(dp[j]), float64(dp[j-arr[i]]+1))) // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    fmt.Println(dp[n])
}

