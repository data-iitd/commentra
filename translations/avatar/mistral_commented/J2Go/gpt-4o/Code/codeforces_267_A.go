package main // Defining the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Defining the main function
    var n int
    fmt.Scan(&n) // Reading the number of test cases from the user

    for i := 0; i < n; i++ { // Iterating through each test case
        var a, b int
        fmt.Scan(&a, &b) // Reading the two numbers from the user
        fmt.Println(sub(a, b)) // Printing the result of subtracting 'b' from 'a'
    }
}

func sub(a, b int) int { // Defining the sub function for subtracting two numbers
    min := a
    max := b
    if a > b {
        min = b
        max = a
    }
    result := 0 // Initializing the result variable

    for min > 0 { // Iterating as long as the smaller number is greater than zero
        result += max / min // Adding the quotient of the larger number divided by the smaller number to the result
        max = max % min // Updating the larger number by taking the remainder of the larger number with the smaller number
        currMin := min // Storing the current minimum
        currMax := max // Storing the current maximum
        if max < min {
            currMin = max
            currMax = min
        }
        min = currMin // Updating the smaller number
        max = currMax // Updating the larger number
    }

    return result // Returning the final result
}

// <END-OF-CODE>
