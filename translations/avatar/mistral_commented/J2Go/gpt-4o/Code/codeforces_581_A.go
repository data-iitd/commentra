package main // Defining the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Starting the main function
    var a, b int // Declaring two integer variables a and b

    fmt.Scan(&a) // Reading the first integer input and assigning it to variable a
    fmt.Scan(&b) // Reading the second integer input and assigning it to variable b

    count := 0 // Initializing the count variable to 0

    for { // Starting an infinite loop
        if a > 0 && b > 0 { // Checking if both a and b are greater than 0
            count++ // Incrementing the count variable if both conditions are true
            a-- // Decrementing the value of variable a by 1
            b-- // Decrementing the value of variable b by 1
        } else { // If either a or b is not greater than 0
            break // Exiting the loop
        }
    }

    ans := a/2 + b/2 // Calculating the answer by dividing each number by 2 and summing the results

    fmt.Println(count, ans) // Printing the count and answer to the console
}

// <END-OF-CODE>
