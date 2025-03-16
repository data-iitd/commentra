
package main // Start of the main package

import "fmt" // Import the standard input/output package

func main() { // Start of the main function
    var n, a, b uint64 = 0 // Declare variables n, a, and b of type uint64 and initialize them to zero
    var i, j int // Declare variables i and j of type int

    fmt.Scanf("%d", &n) // Read an integer value from the standard input and store it in the variable n

    b = (n * (n - 1)) / 2 // Calculate the sum of numbers from 1 to n-1 and store the result in the variable b

    fmt.Printf("%d\n", b) // Print the value of b to the standard output
}

