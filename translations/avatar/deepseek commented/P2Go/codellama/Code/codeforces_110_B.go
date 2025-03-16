
package main

import "fmt"

const LUCKY = "abcd"
// Define a string LUCKY containing the characters "abcd"

func main() {
    var n int
    // Take an integer input n from the user
    fmt.Scan(&n)

    var s string
    // Initialize an empty string s to store the result

    for i := 0; i < n; i++ {
        // Loop n times to construct the string s
        s += LUCKY[i%4]
        // Append a character from LUCKY to s based on the index i modulo 4
    }

    fmt.Println(s)
    // Print the final string s
}

