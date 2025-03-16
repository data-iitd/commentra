
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an integer variable to hold the input seconds
    var S int

    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Prompt the user to enter the number of seconds
    fmt.Print("Enter the number of seconds: ")
    scanner.Scan()

    // Convert the input string to an integer
    S, _ = strconv.Atoi(scanner.Text())

    // Check if the input seconds are less than 60
    if S < 60 {
        // If less than 60 seconds, print the time in the format 0:0:seconds
        fmt.Printf("0:0:%d\n", S)
    }
    // Check if the input seconds are less than 3600 (1 hour)
    else if S < 3600 {
        // If less than 1 hour, print the time in the format 0:minutes:seconds
        fmt.Printf("0:%d:%d\n", S/60, S%60)
    }
    // If the input seconds are 3600 or more (1 hour or more)
    else {
        // Print the time in the format hours:minutes:seconds
        fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)
    }
}

