package main

import "fmt"

// swap swaps the values of two integers
func swap(a, b *int) {
    tmp := *a // tmp holds the value pointed by a
    *a = *b   // *a holds the value pointed by b
    *b = tmp  // *b holds the value stored in tmp
}

func main() {
    var a, b int // Declare two integer variables to hold user input

    // Infinite loop to continuously read input until termination condition is met
    for {
        fmt.Scanf("%d %d", &a, &b) // Read two integers from user input

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

