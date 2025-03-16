// Importing necessary Go libraries for this program
package main

import (
    "fmt" // For formatted I/O
)

func main() {
    // Reading an integer value from the user input
    var x int
    fmt.Scan(&x)

    // Determining a boolean value based on the condition x equals to 1
    boolValue := x == 1

    // Calculating the result based on the boolean value
    result := 0
    if !boolValue {
        result = 1
    }

    // Writing the result to the standard output
    fmt.Println(result)
}

// <END-OF-CODE>
