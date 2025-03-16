package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n int
    var sum int

    // Read the number of elements from user input
    fmt.Scanf("%d", &n)

    // Declare an array of size n
    var a [n]int

    // Read n elements into the array from user input
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }

    // Iterate through the array to calculate the sum of differences
    for i := 1; i < n; i++ {
        // Check if the previous element is greater than the current element
        if a[i-1] > a[i] {
            // Calculate the difference and add it to the sum
            sum += a[i-1] - a[i]
            // Update the current element to be equal to the previous element
            a[i] = a[i-1]
        }
    }

    // Print the total sum of differences
    fmt.Printf("%d\n", sum)
}

