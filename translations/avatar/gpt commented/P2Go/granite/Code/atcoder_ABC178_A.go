
package main

import (
    "bufio"
    "fmt"
    "os"
)

// Define a function to solve the problem for a given test case
func solve(tc int) {
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read an integer from standard input and scan for any extra whitespace
    scanner.Scan()
    a := scanner.Int()
    
    // Print 1 if the integer is 0, otherwise print 0
    fmt.Println(1)
}

// Initialize the number of test cases
tcs := 1
// Start with the first test case
tc := 1

// Loop through each test case until the specified number of test cases is reached
for tc <= tcs {
    // Call the solve function for the current test case
    solve(tc)
    // Increment the test case counter
    tc += 1
}

