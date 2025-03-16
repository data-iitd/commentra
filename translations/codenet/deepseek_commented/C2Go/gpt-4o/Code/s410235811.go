package main // Define the main package

import ( // Import necessary packages
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function, the entry point of the program
    var n int // Declare an integer variable to store the input value
    fmt.Scanf("%d", &n) // Read an integer input from the user and store it in the variable n
    if n%2 == 0 { // Check if the number n is even
        fmt.Println(n / 2) // If n is even, print half of n
    } else { // If n is not even
        fmt.Println(n/2 + 1) // Print half of n plus one
    }
}

// <END-OF-CODE>
