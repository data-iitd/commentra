package main

import (
    "fmt"
    "strings"
)

func main() {
    // Declare a string variable to hold user input
    var s string
    
    // Read input from the user
    fmt.Scan(&s)
    
    // Replace occurrences of "dream" with "D"
    s = strings.Replace(s, "dream", "D", -1)
    
    // Replace occurrences of "erase" with "E"
    s = strings.Replace(s, "erase", "E", -1)
    
    // Remove occurrences of "Der" from the string
    s = strings.Replace(s, "Der", "", -1)
    
    // Remove occurrences of "Er" from the string
    s = strings.Replace(s, "Er", "", -1)
    
    // Remove occurrences of "D" from the string
    s = strings.Replace(s, "D", "", -1)
    
    // Remove occurrences of "E" from the string
    s = strings.Replace(s, "E", "", -1)
    
    // Trim any leading or trailing whitespace from the string
    s = strings.TrimSpace(s)

    // Check if the resulting string is empty
    if s == "" {
        // If the string is empty, print "YES"
        fmt.Println("YES")
    } else {
        // If the string is not empty, print "NO"
        fmt.Println("NO")
    }
}
