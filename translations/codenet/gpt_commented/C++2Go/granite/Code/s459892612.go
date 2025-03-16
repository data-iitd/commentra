
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Declare three integer variables to hold input values
    var a, b, c int

    // Read three integers from standard input
    if scanner.Scan() {
        a, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        b, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        c, _ = strconv.Atoi(scanner.Text())
    }

    // Check if the sum of a and b is greater than or equal to c
    if a+b >= c {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}

