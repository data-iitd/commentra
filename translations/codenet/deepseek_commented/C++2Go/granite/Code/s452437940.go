
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to store user input
    var a, b, x int64
    
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read three integers from standard input
    if scanner.Scan() {
        a, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }
    if scanner.Scan() {
        b, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }
    if scanner.Scan() {
        x, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    }
    
    // Calculate the number of multiples of x between a and b inclusive
    s := (b / x - a / x)
    
    // Check if a is a multiple of x and adjust the count accordingly
    if a%x == 0 {
        s++
    }
    
    // Print the result
    fmt.Println(s)
}

