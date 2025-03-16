package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

// Define the array of substrings to check against
var divide = [...]string{"dream", "dreamer", "erase", "eraser"}

func main() {
    // Read the input string from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    S, _ := reader.ReadString('\n')
    // Reverse the input string to facilitate checking from the end
    S = reverse(S)
    // Reverse each of the substrings in the divide array for matching
    for i := 0; i < len(divide); i++ {
        divide[i] = reverse(divide[i])
    }

    // Initialize a flag to determine if the string can be fully divided
    can := true
    // Start checking the string from the beginning
    for i := 0; i < len(S); {
        can2 := false // Flag to check if we can divide with any of the substrings
        // Iterate through each substring in the divide array
        for j := 0; j < len(divide); j++ {
            d := divide[j]
            // Check if the current substring matches the beginning of the remaining string
            if S[i:i+len(d)] == d { // If we can divide with d
                can2 = true // Set the flag to true
                i += len(d) // Move the index forward by the length of the matched substring
            }
        }
        // If no substring matched, set the can flag to false and break the loop
        if!can2 { // If we couldn't divide the string
            can = false
            break
        }
    }

    // Output the result based on whether the string can be fully divided
    if can {
        fmt.Println("YES") // If it can be divided, print "YES"
    } else {
        fmt.Println("NO") // Otherwise, print "NO"
    }
}

// Reverse a string
func reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

