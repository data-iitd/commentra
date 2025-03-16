
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables
    var n uint64 // Declare an unsigned 64-bit integer variable to store the input number
    var flg bool = false // Declare a boolean variable (flag) and initialize it to false

    // Create a new scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the input number
    if scanner.Scan() {
        n, _ = strconv.ParseUint(scanner.Text(), 10, 64) // Convert the input string to an unsigned 64-bit integer
    }

    // Check if n is less than 4
    if n < 4 {
        fmt.Println("No") // Print "No" and exit the program
        return
    }

    // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for i := uint64(0); i <= n/4; i++ { // Outer loop: i from 0 to n/4
        for j := uint64(0); j <= n/7; j++ { // Inner loop: j from 0 to n/7
            if i*4+j*7 == n { // Check if the sum of i*4 and j*7 equals n
                flg = true // Set the flag to true if found
                break // Exit both loops
            }
        }
        if flg {
            break // Exit the outer loop if flag is true
        }
    }

    // Print the result
    if flg {
        fmt.Println("Yes") // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
    } else {
        fmt.Println("No") // Print "No" otherwise
    }
}

