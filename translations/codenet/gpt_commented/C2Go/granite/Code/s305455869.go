
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to hold input values and the result
    var a, b int
    var ans int

    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read two integers from standard input
    if scanner.Scan() {
        a, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        b, _ = strconv.Atoi(scanner.Text())
    }

    // Initialize the answer variable to zero
    ans = 0

    // Determine the value of ans based on the value of a
    if a >= 13 {
        // If a is 13 or greater, set ans to b
        ans = b
    } else if a >= 6 {
        // If a is between 6 and 12, set ans to half of b
        ans = b / 2
    }

    // Output the result
    fmt.Println(ans)
}

