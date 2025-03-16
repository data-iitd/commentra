package main

import (
    "fmt"
)

func main() {
    // Declare two integer variables x and y
    var x, y int

    // Read an integer value from the user and store it in variable x
    fmt.Scan(&x)

    // Calculate the cube of x and store the result in variable y
    y = x * x * x

    // Print the result (the cube of x) to the console
    fmt.Println(y)
}

// <END-OF-CODE>
