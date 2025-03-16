package main

import (
    "fmt"
)

func main() {
    var a, b int // Declare two integer variables 'a' and 'b'
    var ans int  // Declare an integer variable 'ans' to store the answer

    fmt.Scanf("%d %d", &a, &b) // Read two integers from the standard input and store them in variables 'a' and 'b'

    ans = 0 // Initialize the answer variable 'ans' to zero

    // Check if 'a' is greater than or equal to 13
    if a >= 13 {
        ans = b // If 'a' is greater than or equal to 13, then the answer is 'b'
    } else if a >= 6 { // Else if 'a' is greater than or equal to 6
        ans = b / 2 // If 'a' is greater than or equal to 6, then the answer is half of 'b'
    }

    fmt.Println(ans) // Print the answer to the standard output
}

// <END-OF-CODE>
