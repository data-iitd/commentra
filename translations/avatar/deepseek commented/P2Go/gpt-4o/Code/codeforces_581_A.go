package main

import (
    "fmt"
)

func main() {
    var n int
    fmt.Scan(&n)  // Taking an integer input from the user

    factorial := 1  // Initializing a variable to store the factorial result
    for i := 1; i <= n; i++ {  // Starting a loop from 1 to the input number (inclusive)
        factorial *= i  // Multiplying the factorial by the current number
    }
    fmt.Println(factorial)  // Printing the factorial result
}

// <END-OF-CODE>
