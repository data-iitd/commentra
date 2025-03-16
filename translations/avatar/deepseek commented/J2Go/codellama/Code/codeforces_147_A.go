
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func isLatinLetter(c byte) bool {
    return c >= 'a' && c <= 'z'
}

func isPunctuation(c byte) bool {
    if c == '.' {
        return true
    }
    if c == ',' {
        return true
    }
    if c == '!' {
        return true
    }
    if c == '?' {
        return true
    }
    return false
}

func main() {
    // Create a new scanner from the input file
    scanner := bufio.NewScanner(os.Stdin)
    // Read the input string
    scanner.Scan()
    s := scanner.Text()
    // Create a new string builder to build the output string
    sb := strings.Builder{}
    // Get the length of the input string
    n := len(s)
    // Append the first character of the input string to the string builder
    sb.WriteByte(s[0])
    // Loop through the input string starting from the second character
    for i := 1; i < n; i++ {
        c := s[i]
        // Check if the character is a Latin letter
        if isLatinLetter(c) {
            // If the previous character is not a Latin letter, add a space
            if !isLatinLetter(s[i-1]) {
                sb.WriteByte(' ')
            }
            // Append the current Latin letter to the string builder
            sb.WriteByte(c)
        }
        // Check if the character is a punctuation mark
        else if isPunctuation(c) {
            // Append the punctuation mark to the string builder
            sb.WriteByte(c)
        }
    }
    // Print the final string with spaces added between Latin letters
    fmt.Println(sb.String())
}

