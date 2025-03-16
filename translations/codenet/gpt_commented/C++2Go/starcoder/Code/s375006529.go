package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare a string variable to hold the input
    var s string
    
    // Read the input string from the user
    fmt.Scanln(&s)
    
    // Get the size of the input string
    n := len(s)
    
    // Initialize an array to count occurrences of each character (a-z)
    v := make([]int, 26)
    
    // Count the frequency of each character in the string
    for i := 0; i < n; i++ {
        v[int(s[i] - 'a')]++ // Increment the count for the corresponding character
    }
    
    // Assume the answer is "Yes" initially
    ans := "Yes"
    
    // Check if each character's count is even
    for i := 0; i < 26; i++ {
        if v[i] % 2!= 0 { // If any character has an odd count
            ans = "No" // Set answer to "No"
            break // Exit the loop early as we found an odd count
        }
    }
    
    // Output the result
    fmt.Println(ans)
}

