package main // Declaring the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // The main function is the starting point of the program
    var a, b, ar, le int // Declaring variables a, b, ar (result of multiplication), and le (result of addition and multiplication by 2)

    fmt.Scanf("%d %d", &a, &b) // Reading two integers from the user and storing them in variables a and b

    ar = a * b // Multiplying the values of variables a and b and storing the result in variable ar

    le = 2 * (a + b) // Multiplying the sum of variables a and b by 2 and storing the result in variable le

    fmt.Printf("%d %d\n", ar, le) // Printing the values of variables ar and le to the console
}

// Indicating that the program has run successfully
