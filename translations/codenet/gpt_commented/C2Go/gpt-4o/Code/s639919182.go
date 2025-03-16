package main

import (
    "fmt"
)

func main() {
    // Declare a slice to hold 10 integers
    v := make([]int, 10)
    
    // Initialize a variable to hold the sum of the integers
    sum := 0
    
    // Prompt the user to enter 10 integers and store them in the slice
    for i := 0; i < 10; i++ {
        fmt.Scan(&v[i])
    }
    
    // Calculate the sum of the integers stored in the slice
    for i := 0; i < 10; i++ {
        sum += v[i]
    }
    
    // Output the calculated sum to the console
    fmt.Println(sum)
}

// <END-OF-CODE>
