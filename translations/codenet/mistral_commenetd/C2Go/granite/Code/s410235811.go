
package main

import "fmt"
// Import the standard input/output library package.

func main(){
    var n int
    // Declare an integer variable 'n' to store the user input.

    fmt.Scan(&n)
    // Use the fmt.Scan function to read an integer value from the standard input
    // and store it in the variable 'n'.

    if n%2 == 0 {
        fmt.Println(n/2)
        // If the number 'n' is even, print the value of 'n/2' as the output.
    } else {
        fmt.Println((n/2)+1)
        // If the number 'n' is odd, print the value of '(n/2)+1' as the output.
    }
}

// 