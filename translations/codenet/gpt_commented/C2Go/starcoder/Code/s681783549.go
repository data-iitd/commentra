package main

import "fmt"

func main() {
    // Declare an integer variable for iteration and a character array to store input
    var i int
    var S [6]byte

    // Read a string input from the user
    fmt.Scanf("%s", &S)

    // Iterate through each character in the string until the null terminator is reached
    for i = 0; S[i]!= 0; i++ {
        // Check if the current character is 'A' and the next character is 'C'
        if S[i] == 'A' && S[i+1] == 'C' {
            // If the condition is met, print "Yes" and exit the program
            fmt.Println("Yes")
            return
        }
    }

    // If the loop completes without finding "AC", print "No"
    fmt.Println("No")
    return
}

