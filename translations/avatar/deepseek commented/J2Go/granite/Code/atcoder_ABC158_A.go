

package main

import (
    "bufio"
    "fmt"
    "os"
)

// Import statements: These are importing necessary packages from the Go standard library.

func main() {
    reader := bufio.NewReader(os.Stdin) // Setting up the input reader to read from the console.
    writer := bufio.NewWriter(os.Stdout) // Setting up the output writer to write to the console.
    s := readString(reader) // Reading the input string from the console.
    if contains(s, "A") && contains(s, "B") { // Checking if the string contains both 'A' and 'B'.
        writer.WriteString("Yes\n") // Writing "Yes" to the console.
    } else {
        writer.WriteString("No\n") // Writing "No" to the console.
    }
    writer.Flush() // Flushing the output writer to ensure all data is written to the console.
}

// readString function: This function reads a string from the console using the provided reader.

func readString(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n') // Reading the string from the console until a newline character is encountered.
    for i := 0; i < len(s); i++ { // Looping through each character in the string.
        if s[i] == '\n' { // If the character is a newline character,
            s = s[:i] // Truncating the string at the newline character.
            break // Breaking out of the loop.
        }
    }
    return s // Returning the string.
}

// contains function: This function checks if a given string contains a specified substring.

func contains(s string, substr string) bool {
    return len(s) >= len(substr) && s[:len(substr)] == substr // Checking if the length of the string is greater than or equal to the length of the substring, and if the first characters of the string match the substring.
}

// 