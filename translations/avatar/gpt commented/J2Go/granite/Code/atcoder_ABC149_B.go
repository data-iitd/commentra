
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
    
    // Read the input values A, B, and K from the scanner
    scanner.Scan()
    tokens := strings.Split(scanner.Text(), " ")
    A, _ := strconv.ParseInt(tokens[0], 10, 64)
    B, _ := strconv.ParseInt(tokens[1], 10, 64)
    K, _ := strconv.ParseInt(tokens[2], 10, 64)
    
    // Perform calculations based on the input values
    x := A
    y := B
    x = A - K
    if x < 0 {
        y = B + x
        x = 0
        if y < 0 {
            y = 0
        }
    }
    
    // Display the results of the calculations
    fmt.Println(x, y)
}

