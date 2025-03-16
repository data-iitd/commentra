
package main

import (
    "fmt"
    "os"
)

func main() {
    var n int // Declare integer variable n
    
    // Read an integer input from the user
    fmt.Fscanf(os.Stdin, "%d\n", &n)
    
    // Calculate and print the result based on the input n
    // The expression (24 + (24 - n)) simplifies to (48 - n)
    fmt.Println(24 + (24 - n))
}

