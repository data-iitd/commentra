package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var s string // Declare a string variable to store the input
    fmt.Scan(&s) // Read input from the user and store it in the string variable 's'
    var a, z int // Declare two integer variables to store the positions of 'A' and 'Z'

    // The first loop iterates through the string to find the position of the first occurrence of 'A'
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            a = i // Assign the position of 'A' to variable 'a' and break the loop
            break
        }
    }

    // The second loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' {
            z = i // Assign the position of 'Z' to variable 'z' and break the loop
            break
        }
    }

    // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    fmt.Println(z - a + 1)
}

// <END-OF-CODE>
