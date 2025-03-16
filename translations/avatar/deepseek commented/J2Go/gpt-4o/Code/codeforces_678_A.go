package main // Step 1: Define the main package.

import (
    "fmt" // Step 2: Import the fmt package for formatted I/O.
)

func main() { // Step 3: Define the main function.
    var n, k int // Step 4: Declare variables n and k.
    
    fmt.Scan(&n) // Step 5: Read an integer value from the user and store it in n.
    fmt.Scan(&k) // Step 6: Read another integer value from the user and store it in k.
    
    n++ // Step 7: Increment the value of n by 1.
    
    z := 0 // Step 8: Initialize a variable z to 0.
    
    if n%k != 0 { // Step 9: Check if n is not divisible by k.
        z = k - n%k // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
    }
    
    fmt.Println(n + z) // Step 10: Print the new value of n plus the value of z.
}

// <END-OF-CODE>
