package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() { // Start of the main function
    var n uint64 // Declare a variable n of type uint64
    var b uint64 = 0 // Declare a variable b of type uint64 and initialize it to zero

    fmt.Scanf("%llu", &n) // Read an unsigned long long integer value from the standard input and store it in n

    b = (n * (n - 1)) / 2 // Calculate the sum of numbers from 1 to n-1 and store the result in b

    fmt.Printf("%llu\n", b) // Print the value of b to the standard output
}

// End of the main function
// <END-OF-CODE>
