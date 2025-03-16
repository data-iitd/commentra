package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements
    n, _ := strconv.Atoi(readLine())

    // Initialize a vector to store the input numbers
    a := make([]int, n)
    // Read the input numbers into the vector
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(readLine())
    }

    // Create a copy of the input vector to store absolute values
    abs_a := make([]int, n)
    copy(abs_a, a)

    // Convert all elements in abs_a to their absolute values
    for i := 0; i < n; i++ {
        if abs_a[i] < 0 {
            abs_a[i] = -abs_a[i]
        }
    }

    // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
    ans := 0
    min := abs_a[0]
    // Iterate through the absolute values to calculate the total sum and find the minimum
    for _, e := range abs_a {
        ans += e // Accumulate the sum of absolute values
        if min > e {
            min = e // Update the minimum absolute value found
        }
    }

    // Count the number of negative numbers in the original array
    num_negative := 0
    for _, e := range a {
        if e < 0 {
            num_negative++ // Increment count for each negative number
        }
    }

    // If the count of negative numbers is odd, adjust the total sum
    if num_negative%2!= 0 {
        ans -= min * 2 // Subtract twice the minimum absolute value from the total sum
    }

    // Output the final result
    fmt.Println(ans)
}

func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    str, _ := buf.ReadString('\n')
    return strings.TrimRight(str, "\r\n")
}

