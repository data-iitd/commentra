
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Define a list containing all the vowels in upper and lower case
    vo := []string{ "a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y" }

    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Prompt the user to enter a string
    fmt.Print("Enter a string: ")
    scanner.Scan()
    a := scanner.Text()

    // Iterate through the string 'a' from the end to the beginning
    for i := len(a) - 1; i >= 0; i-- {
        // If the current character is a space or a question mark, skip it and move on to the next character
        if a[i] =='' || a[i] == '?' {
            continue
        }
        // If the current character is not a space or a question mark, check if it is a vowel or not
        else {
            // Check if the current character is a vowel
            if contains(vo, string(a[i])) {
                // If it is, print "YES" and break out of the loop
                fmt.Println("YES")
                break
            }
            // If it is not, print "NO" and break out of the loop
            else {
                fmt.Println("NO")
                break
            }
        }
    }
}

// Function to check if a given string is present in a slice of strings
func contains(s []string, e string) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

