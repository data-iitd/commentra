package main

import "fmt"

// Declare global variables
var n, r, i, j, p, c int
var a [100]int
var b [100]int

func main() {
    // Infinite loop to continuously accept input until a termination condition is met
    for {
        // Read the values of n and r from the user
        fmt.Scanf("%d %d", &n, &r)

        // Check for the termination condition (both n and r are zero)
        if n == 0 && r == 0 {
            break
        }

        // Initialize array a with values from n down to 1
        for i = 0; i < n; i++ {
            a[i] = n - i
        }

        // Process r operations as specified by the user
        for i = 0; i < r; i++ {
            // Copy current state of array a to array b
            for j = 0; j < n; j++ {
                b[j] = a[j]
            }

            // Read the values of p and c for the current operation
            fmt.Scanf("%d %d", &p, &c)

            // Update the first c elements of array a based on the values from array b
            for j = 0; j < c; j++ {
                a[j] = b[p-1+j]
            }

            // Shift the remaining elements in array a
            for j = c; j < c+p-1; j++ {
                a[j] = b[j-c]
            }
        }

        // Output the first element of array a after all operations
        fmt.Printf("%d\n", a[0])
    }
}

