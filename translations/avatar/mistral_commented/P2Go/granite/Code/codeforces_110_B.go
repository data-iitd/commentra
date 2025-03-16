

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Define a constant string "abcd"
    LUCKY := "abcd"

    // Create a new scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Ask the user to input an integer n
    if!scanner.Scan() {
        fmt.Println("Error: failed to read input")
        return
    }
    n, err := strconv.Atoi(scanner.Text())
    if err!= nil {
        fmt.Println("Error: invalid input")
        return
    }

    // Initialize an empty string s
    s := ""

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for i := 0; i < n; i++ {
        // Add the character at index i % 4 of the string LUCKY to the string s
        s += string(LUCKY[i%4])
    }

    // Print the final string s
    fmt.Println(s)
}

