
package main

import (
    "fmt"
    "os"
)

func main() {
    // Declare variables to hold the input values
    var a int
    var b int

    // Read two integer values from the user
    fmt.Fscanf(os.Stdin, "%d", &a)
    fmt.Fscanf(os.Stdin, "%d", &b)

    // Declare a variable to store the result
    var result int

    // Determine the result based on the comparison of a and b
    if a > b {
        // If a is greater than b, calculate result as 2 * a - 1
        result = 2 * a - 1
    } else if a == b {
        // If a is equal to b, calculate result as 2 * a
        result = 2 * a
    } else {
        // If a is less than b, calculate result as 2 * b - 1
        result = 2 * b - 1
    }

    // Output the result to the console
    fmt.Println(result)
}

