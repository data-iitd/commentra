
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Main function begins here
func main() {
    // Declare variables
    var a, b, x int64

    // Create a new scanner to read input values from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read input values from standard input
    if scanner.Scan() {
        a, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }
    if scanner.Scan() {
        b, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }
    if scanner.Scan() {
        x, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }

    // Calculate the difference between the number of complete x-blocks in b and a
    s := (b / x) - (a / x)

    // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
    if a%x == 0 {
        s++
    }

    // Print the result to standard output
    fmt.Println(s)
}

// End of code