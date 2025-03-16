
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to hold the input values
    var a, b, x int64

    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read three integers from standard input
    scanner.Scan()
    a, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    b, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    x, _ = strconv.ParseInt(scanner.Text(), 10, 64)

    // Calculate the number of multiples of x in the range [a, b]
    s := (b / x - a / x)

    // If 'a' is a multiple of 'x', include it in the count
    if a%x == 0 {
        s++
    }

    // Print the result: the total count of multiples of x in the range
    fmt.Println(s)
}

