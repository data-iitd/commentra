package main

import (
    "fmt"
    "math"
)

func main() {
    var n int // Declare an integer variable 'n' to read the number of elements in the slice 'a'

    // Read the number of elements 'n' from the standard input
    fmt.Scan(&n)

    // Declare a slice 'a' of size 'n'
    a := make([]int64, n)

    // Read the elements of the slice 'a' from the standard input
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i]) // Read the 'i'-th element of the slice 'a'
    }

    // Create a copy of the slice 'a' named 'abs_a' to store the absolute values of its elements
    abs_a := make([]int64, n)
    for i := 0; i < n; i++ {
        if a[i] < 0 {
            abs_a[i] = -a[i] // Make it positive by negating it
        } else {
            abs_a[i] = a[i]
        }
    }

    // Initialize the variables 'ans' and 'min' with zero and the first element of 'abs_a' respectively
    ans := int64(0)
    min := abs_a[0]

    // Iterate through each element of the slice 'abs_a' and update the variables 'ans' and 'min' accordingly
    for _, e := range abs_a {
        ans += e // Add the current element to the variable 'ans'
        if min > e { // Check if the current element is smaller than the current minimum
            min = e // Update the minimum if it is
        }
    }

    // Initialize the variable 'num_negative' with zero and count the number of negative elements in the slice 'a'
    num_negative := 0
    for _, e := range a {
        if e < 0 { // Check if the current element is negative
            num_negative++ // Increment the counter if it is
        }
    }

    // Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
    if num_negative%2 != 0 {
        ans -= min * 2 // Subtract twice the minimum if the number of negative elements is odd
    }

    // Print the final answer 'ans' to the standard output
    fmt.Println(ans)
}

// <END-OF-CODE>
