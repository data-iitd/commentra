package main

import "fmt"

func main() {
    // Declare variables
    var i, N, x int

    x = 0 // Initialize x to 0 to hold the sum

    // Read an integer N from user input
    fmt.Scanf("%d", &N)

    // Loop from 1 to N to calculate the sum of integers
    for i = 1; i <= N; i++ {
        x += i // Add the current value of i to x
    }

    // Print the calculated sum
    fmt.Printf("%d\n", x)
}

