package main // Declaring the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // The entry point of the program
    var n, i, a int // Declaring variables n, i, and a

    fmt.Scan(&n) // Reading an integer value from the user and storing it in variable n

    for i = 1; i <= n; i++ { // Starting a for loop that runs from 1 to n
        a = i // Assigning the value of i to variable a

        if a%3 == 0 { // Checking if the value of a is divisible by 3
            fmt.Printf(" %d", i) // If true, print the value of i to the console
        } else { // If the condition is false
            for a > 0 { // Starting an inner for loop that runs as long as a is greater than 0
                if a%10 == 3 { // Checking if the last digit of the number stored in a is 3
                    fmt.Printf(" %d", i) // If true, print the value of i to the console
                    a = 0 // Setting a to 0 to break out of the inner for loop
                }
                a = a / 10 // Otherwise, moving to the next digit by dividing a by 10
            }
        }
    }
    fmt.Println() // Printing a newline character to move the cursor to the next line
}
