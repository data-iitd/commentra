
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Create a map to hold the count of each letter (a-z)
    count := make(map[rune]int)

    // Read strings from standard input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        // Iterate through each character in the string
        for _, r := range scanner.Text() {
            // Check if the character is a lowercase letter
            if 'a' <= r && r <= 'z' {
                // Increment the count for the corresponding letter
                count[r]++
            } 
            // Check if the character is an uppercase letter
            else if 'A' <= r && r <= 'Z' {
                // Increment the count for the corresponding letter (converted to lowercase)
                count[unicode.ToLower(r)]++
            }
        }
    }

    // Print the count of each letter from 'a' to 'z'
    for r := 'a'; r <= 'z'; r++ {
        fmt.Printf("%c : %d\n", r, count[r])
    }
}

