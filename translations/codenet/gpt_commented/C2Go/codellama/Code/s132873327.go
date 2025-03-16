package main

import "fmt"

func main() {
    // Declare an integer variable to hold the input value
    var x int

    // Read an integer value from the user and store it in variable x
    fmt.Scanf("%d", &x)

    // Calculate the cube of the input value and print the result
    fmt.Printf("%d\n", x*x*x)
}

