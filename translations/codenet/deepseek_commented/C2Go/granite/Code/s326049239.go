
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Main function to execute the program
func main() {
    reader := bufio.NewReader(os.Stdin) // Create a reader to read input from the standard input
    for {
        a, _ := strconv.Atoi(read(reader)) // Read an integer 'a' from the input
        if a < 3 { // Check if 'a' is less than 3
            fmt.Println(0) // Print 0 if 'a' is less than 3
        } else {
            b := a // Store the initial value of 'a' in 'b' for later use
            for a > 0 { // Decrement 'a' until it becomes 0
                b-- // Decrement 'b' in each iteration
                c++ // Increment 'c' in each iteration
                if c == 3 { // Check if 'c' equals 3
                    k++ // Increment 'k'
                    c = 0 // Reset 'c' to 0
                }
            }
            fmt.Println(k) // Print the number of times 'c' reset to 0
        }
    }
}

func read(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine() // Read a line of input from the reader
    return string(str) // Return the input as a string
}

