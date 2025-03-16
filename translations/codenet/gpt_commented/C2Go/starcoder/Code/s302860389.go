package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold input numbers and intermediate values
    inputNumbers := make([]byte, 5) // Array to store input numbers as characters
    temp := make([]byte, 2)         // Temporary array to convert characters to integers
    a, b, c, d := 0, 0, 0, 0      // Variables to hold the individual numbers
    sum := 0                      // Variable to hold the calculated sum
    symbols := make([]byte, 3)     // Array to store the symbols used in the expression

    // Read a string of numbers from user input
    fmt.Scanf("%s", &inputNumbers)

    // Set the second character of temp to null terminator for string conversion
    temp[1] = byte(0)

    // Convert each character to an integer and store in respective variables
    temp[0] = inputNumbers[0]
    a, _ = strconv.Atoi(string(temp))
    temp[0] = inputNumbers[1]
    b, _ = strconv.Atoi(string(temp))
    temp[0] = inputNumbers[2]
    c, _ = strconv.Atoi(string(temp))
    temp[0] = inputNumbers[3]
    d, _ = strconv.Atoi(string(temp))

    // Iterate through all combinations of addition and subtraction for the four numbers
    for i := 0; i < 2; i++ { // Loop for the first operation (a + b or a - b)
        for j := 0; j < 2; j++ { // Loop for the second operation (result + c or result - c)
            for k := 0; k < 2; k++ { // Loop for the third operation (result + d or result - d)
                // Determine the first operation (addition or subtraction with a and b)
                if i == 0 {
                    sum = a + b // Perform addition
                    symbols[0] = byte('+') // Store the symbol used
                } else {
                    sum = a - b // Perform subtraction
                    symbols[0] = byte('-') // Store the symbol used
                }

                // Determine the second operation (addition or subtraction with c)
                if j == 0 {
                    sum = sum + c // Perform addition
                    symbols[1] = byte('+') // Store the symbol used
                } else {
                    sum = sum - c // Perform subtraction
                    symbols[1] = byte('-') // Store the symbol used
                }

                // Determine the third operation (addition or subtraction with d)
                if k == 0 {
                    sum = sum + d // Perform addition
                    symbols[2] = byte('+') // Store the symbol used
                } else {
                    sum = sum - d // Perform subtraction
                    symbols[2] = byte('-') // Store the symbol used
                }

                // Check if the calculated sum equals 7
                if sum == 7 {
                    // Print the expression that results in 7
                    fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

                    os.Exit(0) // Exit the program after finding the first valid expression
                }
            }
        }
    }

    os.Exit(0) // Return 0 to indicate successful execution
}

