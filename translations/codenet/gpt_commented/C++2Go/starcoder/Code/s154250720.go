package main

import (
    "fmt"
    "sort"
)

// Define constants for maximum size and infinity value
const maxn = 200000 + 10
const INF = int(1e8)

// Arrays to hold input values and sorted values
var maps [maxn]int
var num [maxn]int

func main() {
    var n int // Variable to hold the number of elements

    // Continuously read input until EOF
    for {
        fmt.Scanf("%d", &n)
        if n == 0 {
            break
        }

        // Read n integers into the maps array and copy to num array
        for i := 1; i <= n; i++ {
            fmt.Scanf("%d", &maps[i])
            num[i] = maps[i]
        }

        // Sort the maps array to find the median
        sort.Ints(maps[1:n+1])

        // Calculate the index for the median element
        m := n / 2

        // For each element in the original array, determine and print the appropriate value
        for i := 1; i <= n; i++ {
            // If the current number is less than or equal to the median
            if num[i] <= maps[m] {
                // Print the next higher number (the one after the median)
                fmt.Printf("%d\n", maps[m+1])
            } else {
                // Print the median value
                fmt.Printf("%d\n", maps[m])
            }
        }
    }
}

