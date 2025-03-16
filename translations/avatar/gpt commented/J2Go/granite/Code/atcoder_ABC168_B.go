
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read an integer K from the user, which represents the maximum length of the string to display
    scanner.Scan()
    K, _ := strconv.Atoi(scanner.Text())
    
    // Read a string S from the user
    scanner.Scan()
    S := scanner.Text()
    
    // Check if the length of the string S is less than or equal to K
    if len(S) <= K {
        // If true, print the string S as it is
        fmt.Println(S)
    } else {
        // If false, print the first K characters of S followed by "..."
        fmt.Println(S[:K] + "...")
    }
}

