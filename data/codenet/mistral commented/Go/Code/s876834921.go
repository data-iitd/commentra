
package main

import (
    "fmt"
    "strings"
)

// Initialize an empty string variable 's'
var s string

// Read a string input from the user using 'fmt.Scan' function
fmt.Scan(&s)

// Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using 'strings.Replace' function
s = strings.Replace(s, "dream", "D", -1)
s = strings.Replace(s, "erase", "E", -1)

// Remove the substrings "Der" and "Er" from the string 's' using 'strings.Replace' function
s = strings.Replace(s, "Der", "", -1)
s = strings.Replace(s, "Er", "", -1)

// Remove leading and trailing spaces from the string 's' using 'strings.TrimSpace' function
s = strings.TrimSpace(s)

// Check if the string 's' is empty or not
if s == "" {
    // Print "YES" if the string 's' is empty
    fmt.Println("YES")
} else {
    // Print "NO" if the string 's' is not empty
    fmt.Println("NO")
}

// End of the code
