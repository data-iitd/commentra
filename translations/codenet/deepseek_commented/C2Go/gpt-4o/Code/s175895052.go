package main  // Declare the main package

import (
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {
    var n string  // Declare a string variable to store the input
    fmt.Scan(&n)  // Read a string from the user input and store it in the variable n

    // Check if any two consecutive characters in the string n are the same
    if (len(n) >= 3 && ((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]))) {
        fmt.Println("Yes")  // Print "Yes" if the condition is true
    } else {
        fmt.Println("No")  // Print "No" if the condition is false
    }
}

// <END-OF-CODE>
