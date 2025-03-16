package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare an integer variable to hold the input value
    var x int

    // Read an integer value from the user and store it in variable x
    fmt.Scanf("%d", &x)

    // Calculate the cube of the input value and print the result
    fmt.Println(x * x * x)

    // Return 0 to indicate that the program finished successfully
    os.Exit(0)
}

