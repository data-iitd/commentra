
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare variables:'reader' for reading input, 'ch' for character input, 'alpha' map to count occurrences of each letter, 'letter' for the current letter, and 'ok' for indicating if the letter is found in the map
    reader := bufio.NewReader(os.Stdin)
    var ch byte
    alpha := make(map[byte]int)
    var letter byte
    var ok bool

    // Infinite loop to read characters until EOF (End of File) is encountered
    for {
        ch, _, err := reader.ReadByte() // Read a byte from standard input
        if err!= nil {
            break // Exit the loop if EOF is reached
        }

        // Check if the character is an alphabet letter
        if (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') {
            // Convert the character to lowercase if it is uppercase
            if ch >= 'A' && ch <= 'Z' {
                letter = ch + 32 // Convert uppercase to lowercase
            } else {
                letter = ch
            }

            // Increment the count of the letter in the alpha map
            alpha[letter], ok = alpha[letter] + 1, true // If the letter is not found in the map, set its count to 1
        }
    }

    // Print the count of each letter from 'a' to 'z'
    for ch = 'a'; ch <= 'z'; ch++ {
        fmt.Printf("%c : %d\n", ch, alpha[ch]) // Output the letter and its count
    }
}

