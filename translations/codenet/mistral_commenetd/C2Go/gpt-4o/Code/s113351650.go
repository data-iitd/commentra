package main // Declaring the main package

import "fmt" // Importing the fmt package for formatted I/O

func main() { // The main function is the starting point of the program
    var x int // Declaring an integer variable named x

    fmt.Scanf("%d", &x) // Reading an integer value from the standard input and storing it in the variable x

    if x == 0 { // If the value of x is 0
        fmt.Println("1") // Print the value 1 followed by a newline character
    }
    if x == 1 { // If the value of x is 1
        fmt.Println("0") // Print the value 0 followed by a newline character
    }
}

// <END-OF-CODE>
