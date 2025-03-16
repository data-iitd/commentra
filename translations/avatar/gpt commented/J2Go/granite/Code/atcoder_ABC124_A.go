
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Reading two integers from the user
    scanner.Scan()
    a, _ := strconv.Atoi(scanner.Text()) // First integer input
    scanner.Scan()
    b, _ := strconv.Atoi(scanner.Text()) // Second integer input
    
    sum := 0 // Initializing a variable to hold the sum of selected integers
    
    // Loop to iterate twice to calculate the sum
    for i := 0; i < 2; i++ {
        // Check if 'a' is greater than or equal to 'b'
        if a >= b {
            sum += a // Add 'a' to the sum
            a = a - 1 // Decrement 'a' by 1
        } else {
            sum += b // Add 'b' to the sum
            b = b - 1 // Decrement 'b' by 1
        }
    }
    
    // Output the final sum to the console
    fmt.Println(sum)
}

