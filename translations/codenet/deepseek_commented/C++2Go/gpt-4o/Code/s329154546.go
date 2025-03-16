package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
    "sort" // Import the sort package for sorting
)

func main() {
    var N, L int // Declare variables for the number of strings and the length of each string
    fmt.Scan(&N, &L) // Read the number of strings and the length of each string

    S := make([]string, N) // Create a slice to store the strings
    for i := 0; i < N; i++ { // Loop to read each string
        fmt.Scan(&S[i]) // Read each string and store it in the slice
    }

    sort.Strings(S) // Sort the slice of strings alphabetically

    for _, str := range S { // Loop to output each sorted string
        fmt.Print(str) // Output each string
    }
    fmt.Println() // Output a newline character
}

// <END-OF-CODE>
