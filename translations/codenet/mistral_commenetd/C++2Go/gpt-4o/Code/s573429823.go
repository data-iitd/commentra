package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function, entry point of the program
    var n uint64 // Declare an unsigned integer variable to store the input number
    var flg bool = false // Declare a boolean variable (flag) and initialize it to false

    // Read the input number
    fmt.Scan(&n)

    // Check if n is less than 4
    if n < 4 {
        fmt.Println("No") // Print "No" and exit the program
        return
    }

    // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for i := uint64(0); i <= n/4; i++ { // Outer loop: i from 0 to n/4
        for j := uint64(0); j <= n/7; j++ { // Inner loop: j from 0 to n/7
            if (i*4 + j*7) == n { // Check if the sum of i*4 and j*7 equals n
                flg = true // Set the flag to true if found
                break // Exit the inner loop
            }
        }
        if flg { // Exit the outer loop if flag is true
            break
        }
    }

    // Print the result
    if flg {
        fmt.Println("Yes") // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
    } else {
        fmt.Println("No") // Print "No" otherwise
    }
}

// <END-OF-CODE>
