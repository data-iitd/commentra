package main  // Step 1: Define the main package.

import (  // Step 2: Import necessary packages.
    "fmt"  // Import the fmt package for formatted I/O.
)

func main() {  // Step 3: Define the main function.
    var m rune  // Step 4: Declare a character variable 'm' as a rune.
    var a, b int  // Step 5: Declare two integers 'a' and 'b'.
    c := make([]int, 256)  // Step 6: Create a slice 'c' of size 256 to store results.
    var i, j int  // Declare two integer variables 'i' and 'j'.

    for {  // Step 7: Start an infinite loop.
        fmt.Scanf("%d %c %d", &a, &m, &b)  // Step 8: Read three inputs: an integer 'a', a character 'm', and an integer 'b'.
        if m == '?' {  // Step 9: Check if the character 'm' is '?'. If true, break the loop.
            break
        }
        if m == '+' {  // Step 10: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the slice 'c' at index 'i'.
            c[i] = a + b
        }
        if m == '-' {
            c[i] = a - b
        }
        if m == '*' {
            c[i] = a * b
        }
        if m == '/' {
            c[i] = a / b
        }
        i++  // Increment 'i' after each operation.
    }

    for j = 0; j < i; j++ {  // Step 11: After the loop ends, start another loop to print the results stored in the slice 'c' from index 0 to 'i-1'.
        fmt.Println(c[j])
    }
}  // Step 12: End of the main function.

