
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Prompt the user to enter a line of input
    fmt.Print("Enter a line of input: ")
    scanner.Scan()

    // Get the input line as a string
    input := scanner.Text()

    // Replace the character at index 5 with a space
    input = strings.Replace(input, "", 6)

    // Replace the character at index 13 with a space
    input = strings.Replace(input, "", 14)

    // Print the modified string to the console
    fmt.Println(input)

    // Return 0 to indicate successful execution of the program
    os.Exit(0)
}

