
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Read the integer input which represents the length of the strings
    reader := bufio.NewReader(os.Stdin)
    nTemp, err := fmt.Fscanf(reader, "%d\n", &n)
    checkError(err)
    
    // Read the first string and convert it to a list of characters
    sTemp, err := fmt.Fscanf(reader, "%s\n", &s)
    checkError(err)
    
    // Read the second string and convert it to a list of characters
    tTemp, err := fmt.Fscanf(reader, "%s\n", &t)
    checkError(err)
    
    // Check if both strings are identical
    if s == t {
        // If they are the same, print the length of the strings
        fmt.Println(n)
    } else {
        // Initialize a counter to keep track of the matching characters
        cnt := 0
        
        // Iterate over each character in the first string
        for i := 0; i < n; i++ {
            // For each character, check the subsequent characters in the second string
            for j := 0; j < n - i; j++ {
                // If characters at the current position do not match, break the inner loop
                if string(s[i+j])!= string(t[j]) {
                    break
                }
                
                // If we have matched all characters from this starting point
                if j == n - i - 1 {
                    // Update the count of matching characters
                    cnt = n - i
                }
            }
        }
        
        // Print the result based on the number of matching characters found
        fmt.Println(2 * n - cnt)
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

