package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare an array to hold up to 10,000 integers
    var a [10000]int
    // Initialize a variable to hold the sum of the integers
    var sum int64

    // Read the number of integers to be processed
    n, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))

    // Read n integers from input and calculate their sum
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i]) // Read each integer into the array
        sum += int64(a[i])      // Add the integer to the sum
    }

    // Initialize min and max with the first element of the array
    min, max := a[0], a[0]

    // Iterate through the array to find the minimum and maximum values
    for i := 1; i < n; i++ {
        if a[i] > max {
            max = a[i]
        }
        if a[i] < min {
            min = a[i]
        }
    }

    // Print the minimum, maximum, and sum of the integers
    fmt.Printf("%d %d %d\n", min, max, sum)
}

