package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var str string // Declare a string variable to hold user input

    // Read a string input from the user
    fmt.Scan(&str)

    // Check if the characters at positions 2 and 3 are the same,
    // and if the characters at positions 4 and 5 are the same
    if str[2] == str[3] && str[4] == str[5] {
        fmt.Println("Yes") // If both conditions are true, output "Yes"
    } else {
        fmt.Println("No") // If either condition is false, output "No"
    }
}

// <END-OF-CODE>
