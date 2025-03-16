package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var (
        i, sum int
        flag   int
        x      string
    )

    // Read the first input string
    fmt.Scanf("%s", &x)

    // Loop to process input until the termination condition is met
    for {
        // Iterate through the characters of the input string
        for i = 0; i < len(x); i++ {
            // Check for the end of the string (null character)
            if x[i] == 0 {
                // Print the sum of the digits in the string
                fmt.Println(sum)
                break // Exit the loop if end of string is reached
            } else {
                // Convert character to integer and add to sum
                sum += int(x[i]) - 0x30 // '0' is represented by 0x30 in ASCII
            }
        }

        // Reset sum for the next input
        sum = 0

        // Read the next input string
        fmt.Scanf("%s", &x)

        // Continue until the first character is '0'
        if x[0]!= 0x30 {
            break
        }
    }

    os.Exit(0) // Exit the program
}

