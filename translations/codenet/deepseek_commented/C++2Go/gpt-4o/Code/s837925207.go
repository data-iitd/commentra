package main // Declare the main package.

import ( // Import necessary packages.
    "fmt" // Import the fmt package for formatted I/O.
)

func main() { // The main function is the entry point of the program.
    var x int // Declare an integer variable x.
    var ans int // Declare an integer variable ans.

    fmt.Scan(&x) // Read an integer from standard input and store it in x.

    ans = x + x*x + x*x*x // Calculate the result by adding x, x*x, and x*x*x.

    fmt.Println(ans) // Print the result to standard output.
}

// <END-OF-CODE>
