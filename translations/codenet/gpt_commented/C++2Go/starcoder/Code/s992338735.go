package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Continuously read input until a non-positive integer is entered
    for {
        var N int
        if _, err := fmt.Scanf("%d", &N); err!= nil {
            break
        }
        if N <= 0 {
            break
        }

        var M, m, addup, i int
        M = -1 // Maximum value initialized to -1 (less than any possible input)
        m = 1001 // Minimum value initialized to 1001 (greater than any possible input)
        addup = 0 // Variable to accumulate the sum of inputs

        // Loop to read N integers
        for i = 0; i < N; i++ {
            var S int
            if _, err := fmt.Scanf("%d", &S); err!= nil {
                break
            }

            addup += S // Add the current integer to the total sum

            // Update the maximum value if the current integer is greater
            if S > M {
                M = S
            }

            // Update the minimum value if the current integer is smaller
            if S < m {
                m = S
            }
        }

        // Calculate the average excluding the maximum and minimum values
        // and print the result
        fmt.Printf("%.1f\n", float64(addup-M-m)/(N-2))
    }
}

