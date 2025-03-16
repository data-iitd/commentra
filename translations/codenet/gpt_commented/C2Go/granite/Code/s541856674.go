
package main

import "fmt"

func main() {
    // Declare variables to hold the input values
    var N int // Variable to store the first input value
    var R int // Variable to store the second input value

    // Read two integers from user input
    fmt.Scan(&N, &R)

    // Check if the first input value N is greater than or equal to 10
    if N >= 10 {
        // If N is 10 or more, print the value of R as is
        fmt.Println(R)
    } else {
        // If N is less than 10, calculate and print R adjusted by the difference from 10
        fmt.Println(R + 100 * (10 - N))
    }

    // Return 0 to indicate successful completion of the program
    return 0
}


