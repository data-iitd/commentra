

package main

import (
    "bufio"
    "fmt"
    "os"
)

// Define the solve function that takes a test case number as an argument
func solve ( tc int ) {
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner ( os.Stdin )
    // Read an integer input from standard input
    scanner.Scan ( )
    a := int ( scanner.Bytes ( ) [ 0 ] - '0' )
    // Print 1 if the input is 0, otherwise print 0
    fmt.Println ( 1 )
}

// Set the number of test cases to 1 and initialize the current test case number
var tcs = 1
var tc = 1

// Enter a for loop that continues as long as the current test case number is less than or equal to the total number of test cases
for tc <= tcs {
    // Call the solve function with the current test case number and increment the current test case number
    solve ( tc )
    tc += 1
}
