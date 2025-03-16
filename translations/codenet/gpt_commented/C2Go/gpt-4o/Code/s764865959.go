package main

import (
    "fmt"
)

func main() {
    // Declare an integer variable to hold the input value
    var x int

    // Read an integer value from the user and store it in variable x
    fmt.Scan(&x)

    // Calculate the cube of the input value by multiplying it by itself twice
    x = x * x * x

    // Print the result (the cube of the input value) to the console
    fmt.Println(x)

    // Return 0 to indicate that the program finished successfully
    // (In Go, the main function does not need to return a value)
}

// <END-OF-CODE>
