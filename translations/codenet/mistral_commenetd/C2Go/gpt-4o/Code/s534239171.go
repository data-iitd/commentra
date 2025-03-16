package main // Declare the main package

import ( // Import necessary packages
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Beginning of main function
    var a, b int // Declare two integer variables
    fmt.Print("Enter two integers: ") // Prompt user to enter two integers
    fmt.Scanf("%d %d", &a, &b) // Read two integers from standard input and store in variables a and b

    n := (a + b) / 2 // Calculate the average of a and b and store the result in variable n

    fmt.Printf("The average of %d and %d is: %d\n", a, b, n) // Display the average on standard output
}

// Program has executed successfully, return integer value 0 to operating system
