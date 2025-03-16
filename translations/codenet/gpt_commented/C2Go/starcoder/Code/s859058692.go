package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables to store the sum, current number, count of numbers, and min/max values
    sum := 0
    m := 0
    n := 0
    i := 0
    min := 0
    max := 0

    // Read the total number of integers to be processed
    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))

    // Loop through each number to read and process
    for i = 0; i < n; i++ {
        // Read the current number
        fmt.Scanf("%d", &m)

        // Add the current number to the sum
        sum += m

        // Initialize min and max with the first number read
        if i == 0 {
            min = m
            max = m
        }

        // Update min if the current number is less than the current min
        if min > m {
            min = m
        }

        // Update max if the current number is greater than the current max
        if max < m {
            max = m
        }
    }

    // Print the minimum, maximum, and sum of the numbers
    fmt.Printf("%d %d %d\n", min, max, sum)
}

