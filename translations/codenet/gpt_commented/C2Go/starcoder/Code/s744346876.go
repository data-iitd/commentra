package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare two integer variables A and B
    var A, B int

    // Read two integers from user input
    fmt.Scanf("%d %d", &A, &B)

    // Check if both A and B are less than 10
    if A < 10 && B < 10 {
        // If both are less than 10, print their product
        fmt.Println(A * B)
    } else {
        // If either A or B is 10 or greater, print -1
        fmt.Println("-1")
    }

    // Return 0 to indicate successful execution
    os.Exit(0)
}

