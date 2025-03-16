package main // Step 1: Define the main package.

import "fmt" // Step 2: Import the fmt package for formatted I/O.

func main() { // Step 3: Define the main function.
    var a, b, ar, le int // Step 4: Declare integer variables a, b, ar, and le.
    fmt.Scanf("%d %d", &a, &b) // Step 5: Read two integers from the user.
    ar = a * b // Step 6: Calculate the area of a rectangle (ar) by multiplying a and b.
    le = 2 * (a + b) // Step 7: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
    fmt.Printf("%d %d\n", ar, le) // Step 8: Print the area and perimeter.
} // Step 9: End of the main function.

