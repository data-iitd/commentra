package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

const N = 2000 // Define a constant N for the size of the array

var num1 int // Declare a global variable num1
var math [N + 1]int // Declare a global array math

func main() { // Main function is the entry point of the program
    var a, num2, ans, sum int // Declare local variables a, num2, ans, and sum
    var i, j int // Declare loop variables

    math[0] = 1 // Initialize the first element of math to 1

    fmt.Scan(&num1) // Read the number of elements in the first set of inputs
    for i = 0; i < num1; i++ { // Loop through num1 times
        fmt.Scan(&a) // Read each element
        sum += a // Update the sum
        for j = sum - a; j >= 0; j-- { // Loop to mark possible sums
            if math[j] == 1 { // If the sum j is possible
                math[j+a] = 1 // Mark sum j+a as possible
            }
        }
    }

    fmt.Scan(&num2) // Read the number of elements in the second set of inputs
    for i = 0; i < num2; i++ { // Loop through num2 times
        fmt.Scan(&ans) // Read each element
        if math[ans] == 1 { // Check if the sum is possible
            fmt.Println("yes") // Print "yes" if possible
        } else {
            fmt.Println("no") // Print "no" if not possible
        }
    }
}

// <END-OF-CODE>
