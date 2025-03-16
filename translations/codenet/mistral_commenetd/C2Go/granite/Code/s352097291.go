

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Initialize variables
    reader := bufio.NewReader(os.Stdin)
    c, _ := reader.ReadString('\n') // Read a string from the standard input and store it in the 'c' variable
    c = strings.TrimSpace(c) // Remove any leading or trailing whitespace from the input string 'c'
    ans := "" // Initialize an empty string to store the output

    // Process the string
    for _, v := range c { // Iterate through each character in the string 'c'
        if v!= 'B' { // If the current character is not 'B'
            ans += string(v) // Append the character to the output string 'ans'
        } else { // If the current character is 'B'
            ans = ans[:len(ans)-1] // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    fmt.Println(ans) // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.

