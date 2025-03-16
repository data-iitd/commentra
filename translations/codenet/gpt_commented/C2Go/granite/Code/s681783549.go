
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a string variable for input and a boolean variable to store the result
    var S string
    var hasAC bool

    // Create a scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read a string input from the user
    if scanner.Scan() {
        S = scanner.Text()
    }

    // Split the string into individual characters and iterate through each character
    for _, char := range strings.Split(S, "") {
        // Check if the current character is 'A' and the next character is 'C'
        if char == "A" && strings.Containsrune(S, 'C') {
            // If the condition is met, set the result to true and break the loop
            hasAC = true
            break
        }
    }

    // Print the result
    if hasAC {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

