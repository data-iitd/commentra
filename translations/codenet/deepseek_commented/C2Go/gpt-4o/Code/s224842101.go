package main // Step 1: Define the main package

import "fmt" // Step 2: Import necessary packages

func main() { // Step 3: Define the main function
    var a, b int // Step 4: Declare necessary variables
    count := make([]int, 4) // Declare a slice to store the count of connections for each node

    for i := 0; i < 3; i++ { // Step 5: Read input values and update the count slice
        fmt.Scan(&a, &b)
        count[a-1]++ // Increment the count for node a
        count[b-1]++ // Increment the count for node b
    }

    s := 1 // Initialize s to 1
    for i := 0; i < 4; i++ {
        s *= count[i] // Step 6: Calculate the product of the counts
    }

    if s == 4 { // Step 7: Check if the product is 4 and print the result
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
} // End of main function

// <END-OF-CODE>
