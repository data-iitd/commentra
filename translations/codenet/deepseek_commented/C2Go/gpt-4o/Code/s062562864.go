package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
    // Declare integer variables to store input values and intermediate results
    var a, b, c, d int

    // Read four integers from the user
    fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

    // Perform multiplication operations and store the results in i and j
    i := a * b
    j := c * d

    // Use an if-else statement to compare the results and print the larger one
    if i > j {
        fmt.Println(i)
    } else {
        fmt.Println(j)
    }
}

// <END-OF-CODE>
