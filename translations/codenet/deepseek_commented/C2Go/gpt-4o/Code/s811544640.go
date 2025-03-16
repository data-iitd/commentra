package main  // Step 1: Define the main package

import "fmt"  // Step 2: Import necessary packages

func main() {  // Step 3: Define the main function
    var a, b, c int  // Step 4: Declare variables

    fmt.Scanf("%d %d %d", &a, &b, &c)  // Step 5: Read input values

    if b > a*c {  // Step 6: Implement the if-else condition
        fmt.Println(c)  // If true, print c
    } else {
        fmt.Println(b / a)  // Otherwise, print b divided by a
    }
}  // Step 7: End of the main function

// <END-OF-CODE>
