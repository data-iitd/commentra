package main

import (
    "fmt"
)

func main() {
    var a int // Declare variable 'a' to store first user input
    var b int // Declare variable 'b' to store second user input
    var result int // Declare variable 'result' to store the result of the computation

    fmt.Scan(&a) // Read the first integer value from the user
    fmt.Scan(&b) // Read the second integer value from the user

    if a > b { // Check if 'a' is greater than 'b'
        result = 2*a - 1 // If true, assign the value '2 * a - 1' to 'result'
    } else if a == b { // Check if 'a' is equal to 'b'
        result = 2 * a // If true, assign the value '2 * a' to 'result'
    } else { // If 'a' is less than 'b'
        result = 2*b - 1 // Assign the value '2 * b - 1' to 'result'
    }

    fmt.Println(result) // Print the value of 'result' to the console
}

// <END-OF-CODE>
