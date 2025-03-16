// Package declaration and importing required library
package main

import "fmt"

// Constants declaration with initializing size of the memory slice
const size = 100001

// Function definition for main function
func main() {
    // Variable declaration and initialization for number of queries and time interval
    var n, t int

    // Initializing memory slice with zero values
    var mem [size]int

    // Reading input values for number of queries and time interval
    fmt.Scan(&n)
    fmt.Scan(&t)

    // Iterating through each query in the input
    for i := 0; i < n; i++ {
        // Reading input values for start and end time intervals
        fmt.Scan(&l)
        fmt.Scan(&r)

        // Updating memory slice values for start and end time intervals
        mem[l] += 1
        mem[r] -= 1
    }

    // Initializing variable for answer
    ans := mem[0]

    // Iterating through each time interval in the memory slice
    for i := 1; i < t + 1; i++ {
        // Updating memory slice values by adding previous value
        mem[i] += mem[i - 1]

        // Updating answer if current memory slice value is greater than previous answer
        if ans < mem[i] {
            ans = mem[i]
        }
    }

    // Printing the final answer
    fmt.Println(ans)

// End of code
}