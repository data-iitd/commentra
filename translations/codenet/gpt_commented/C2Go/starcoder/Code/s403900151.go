package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for input values and loop counters
    var n, r, p, c int

    // Infinite loop to continuously accept input until a termination condition is met
    for {
        // Read the values of n (number of elements) and r (number of operations)
        fmt.Scanf("%d %d ", &n, &r)

        // Check for termination condition: if both n and r are zero, exit the loop
        if n == 0 && r == 0 {
            break
        }

        // Initialize array a with values from 1 to n
        a := make([]int, n)
        for i := 0; i < n; i++ {
            a[i] = i + 1
        }

        // Process each operation
        for i := 0; i < r; i++ {
            // Read the values of p (number of elements to move) and c (number of elements to copy)
            fmt.Scanf("%d %d ", &p, &c)

            // Temporary array b to hold the elements that will be moved
            b := make([]int, c)
            for j := 0; j < c; j++ {
                b[j] = a[n-p-c+1+j] // Copy elements from a to b
            }

            // Shift elements in array a to make space for the new elements
            for j := 0; j < p-1; j++ {
                a[n-p-c+1+j] = a[n-p+j+1] // Move elements to the left
            }

            // Insert the copied elements from b back into array a
            for j, k := n-p-c+1+j, 0; k < c; j, k = j+1, k+1 {
                a[j] = b[k] // Place elements from b into the correct position in a
            }

            /*
            Uncomment the following lines to debug and print the current state of array a
            for j := 0; j < n; j++ {
                fmt.Printf("%d\n", a[j])
            }
            fmt.Printf("---\n")
            */
        }

        // Print the last element of array a after all operations are completed
        fmt.Printf("%d\n", a[n-1])
    }
}

