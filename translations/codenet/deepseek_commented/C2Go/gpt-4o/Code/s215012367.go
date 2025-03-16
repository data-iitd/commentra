package main // Step 1: Declare the main package.

import "fmt" // Step 2: Import the fmt package for formatted I/O.

func main() { // Step 3: Define the main function.
    var a, b, s int // Step 4: Declare three integer variables: a, b, and s.

    fmt.Scanf("%d %d", &a, &b) // Step 5: Read two integers from the user input and store them in variables a and b.

    s = (a * b) - (a + b) + 1 // Step 6: Calculate the value of s using the formula (a*b) - (a + b) + 1.

    fmt.Println(s) // Step 7: Print the value of s.
} // Step 8: End of the main function.

