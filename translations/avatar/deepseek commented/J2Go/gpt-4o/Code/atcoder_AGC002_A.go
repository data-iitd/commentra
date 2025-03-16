package main

import (
    "fmt" // Importing the fmt package to read input and print output
)

func main() {
    var a, b int // Declaring two integer variables

    fmt.Scan(&a) // Reading the first integer input from the user
    fmt.Scan(&b) // Reading the second integer input from the user

    // Checking if the first number is positive
    if a > 0 {
        fmt.Println("Positive") // Printing "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if b >= 0 {
        fmt.Println("Zero") // Printing "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if (b-a+1)%2 == 0 {
        fmt.Println("Positive") // Printing "Positive" if the difference is even
    } 
    else {
        fmt.Println("Negative") // Printing "Negative" if none of the above conditions are met
    }
}

// <END-OF-CODE>
