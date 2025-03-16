package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func check(x, y int) string { // Function declaration: check takes two integer arguments and returns a string
    if y%2 == 0 { // Check if y is even
        t := (y / 2) - x // Calculate t as half of y minus x

        if t >= 0 && (x-t) >= 0 { // Check if t is greater than or equal to zero and if x - t is also greater than or equal to zero
            return "Yes" // If both conditions are true, return "Yes"
        }
    }

    return "No" // If y is not even, return "No"
}

func main() { // Main function declaration
    var x, y int // Declare two integer variables x and y

    fmt.Scan(&x, &y) // Read input values for x and y from standard input

    fmt.Println(check(x, y)) // Call check function with input values and print its return value to standard output
}

// <END-OF-CODE>
