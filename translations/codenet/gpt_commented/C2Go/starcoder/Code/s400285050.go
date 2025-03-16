package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function prototype declaration for 'you' which takes two integers and returns an integer
func you(x, y int) int {
    var z int

    // Infinite loop to perform the Euclidean algorithm
    for {
        z = x % y
        x = y
        y = z

        // Break the loop if y becomes zero or negative
        if y <= 0 {
            break
        }
    }

    // Return the last non-zero value of x, which is the GCD
    return x
}

func main() {
    // Declare variables to hold input values and result
    var x, y, z int

    // Read two integers from user input
    fmt.Scanf("%d %d", &x, &y)

    // Call the 'you' function with the larger and smaller of the two integers
    if x >= y {
        z = you(x, y) // If x is greater than or equal to y, pass x and y to 'you'
    } else {
        z = you(y, x) // Otherwise, pass y and x to 'you'
    }

    // Print the result returned from the 'you' function
    fmt.Printf("%d\n", z)

    // Return 0 to indicate successful completion of the program
    os.Exit(0)
}

