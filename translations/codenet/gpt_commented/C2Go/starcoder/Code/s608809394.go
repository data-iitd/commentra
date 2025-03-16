package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n, i, j, m, s, t int

    // Read the number of elements in the array
    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    // Declare an array of size n
    a := make([]int, n)

    // Read n elements into the array
    for i = 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
    }

    // Initialize total sum variable
    t = 0

    // Outer loop to iterate through each element of the array
    for i = 0; i < n; i++ {
        // Initialize sum for the current element
        s = 0

        // Inner loop to calculate the product of the current element with all subsequent elements
        for j = 1; j < n; j++ {
            // Skip elements that are not after the current element
            if j <= i {
                continue
            }

            // Calculate the product of the current element a[i] and a[j]
            m = a[i] * a[j]

            // Add the product to the sum for the current element
            s = s + m
        }

        // Add the sum of products for the current element to the total
        t = t + s
    }

    // Print the total sum of products
    fmt.Printf("%d\n", t)
}

