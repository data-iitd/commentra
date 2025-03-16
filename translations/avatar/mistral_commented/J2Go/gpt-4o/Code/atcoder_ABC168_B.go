package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function as the entry point of the program
    var K int // Declare an integer variable K
    var S string // Declare a string variable S

    fmt.Scan(&K) // Read the integer K from standard input
    fmt.Scan(&S) // Read the string S from standard input

    if len(S) <= K { // Check if the length of the string S is less than or equal to K
        fmt.Println(S) // If true, print the string S
    } else { // If false
        fmt.Println(S[:K] + "...") // Print the first K characters of S followed by "..."
    }
}

// <END-OF-CODE>
