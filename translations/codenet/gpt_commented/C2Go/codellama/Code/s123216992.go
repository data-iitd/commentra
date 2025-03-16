package main

import "fmt"

// Function to swap the values of two integers
func swap(a *int, b *int) {
    tmp := *a // Temporary variable to hold one of the values during swap
    *a = *b   // Assign the value pointed by b to the location pointed by a
    *b = tmp  // Assign the value stored in tmp to the location pointed by b
}

func main() {
    var a, b int // Declare two integer variables to hold user input

    // Infinite loop to continuously read input until termination condition is met
    for {
        // Read two integers from user input
        fmt.Scan(&a, &b)
        
        // Check for the termination condition (both inputs are zero)
        if a == 0 && b == 0 {
            break
        }

        // If the second number is less than the first, swap them
        if b < a {
            swap(&a, &b)
        }
        
        // Print the sorted values of a and b
        fmt.Printf("%d %d\n", a, b)
    }
}

