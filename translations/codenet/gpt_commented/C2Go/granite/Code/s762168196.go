
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an array to hold up to 10,000 integers
    a := make([]int, 10000)
    var min, max, n, i int
    var sum int64 = 0

    // Read the number of integers to be processed
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

    // Read n integers from input and calculate their sum
    for i = 0; i < n; i++ {
        fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &a[i]) // Read each integer into the array
        sum += int64(a[i])                                 // Add the integer to the sum
    }

    // Initialize min and max with the first element of the array
    max = min = a[0]

    // Iterate through the array to find the minimum and maximum values
    for i = 1; i < n; i++ {
        if a[i] > max {
            max = a[i] // Update max if the current element is greater
        }
        if a[i] < min {
            min = a[i] // Update min if the current element is smaller
        }
    }

    // Print the minimum, maximum, and sum of the integers
    fmt.Printf("%d %d %d\n", min, max, sum)
}

