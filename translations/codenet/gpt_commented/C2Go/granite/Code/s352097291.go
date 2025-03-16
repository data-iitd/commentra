
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a character array 'c' to store the input string and 'ans' to store the result
    c := make([]byte, 11)
    ans := make([]byte, 11)
    
    // Read a string input from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanln(reader, c)
    
    // Iterate through each character of the input string until the null terminator is encountered
    for i := 0; c[i]!= 0; i++ {
        // If the current character is not 'B', append it to the 'ans' string
        if c[i]!= 'B' {
            ans = append(ans, c[i])
        } 
        // If the current character is 'B', remove the last character from 'ans' (if it exists)
        else {
            ans = ans[:len(ans)-1]
        }
    }
    
    // Print the resulting string after processing the input
    fmt.Println(string(ans))
}

