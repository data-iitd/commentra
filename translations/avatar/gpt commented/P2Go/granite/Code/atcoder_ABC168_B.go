
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read an integer input K from the user
    reader := bufio.NewReader(os.Stdin)
    K, _ := strconv.Atoi(reader.ReadLine())
    
    // Read a string input S from the user
    S := reader.ReadLine()
    
    // Check if the length of the string S is less than or equal to K
    if len(S) <= K {
        // If true, return the original string S
        fmt.Println(S)
        return
    }
    
    // If the length of S is greater than K, return the first K characters followed by '...'
    fmt.Println(S[:K] + "...")
}

// Entry point of the program
func main() {
    // Call the main function
    main()
}

