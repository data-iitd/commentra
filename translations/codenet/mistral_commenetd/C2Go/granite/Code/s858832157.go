
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare and initialize variables
    i := 1 // Initialize counter variable i to 1
    reader := bufio.NewReader(os.Stdin) // Create a new reader for standard input
    var Input int // Declare variable to store user input

    for {
        // Read user input and store it in the Input variable
        InputStr, _ := reader.ReadString('\n') // Read user input as a string
        Input, _ := strconv.Atoi(InputStr) // Convert user input string to integer

        // Check if user input is 0
        if Input == 0 {
            // If user input is 0, break out of the loop
            break
        }

        // Print the case number and user input
        fmt.Printf("Case %d: %d\n", i, Input)

        // Increment the counter variable i
        i++
    }
}

