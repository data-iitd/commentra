package main

import "fmt"

func main() {
    // Read an integer input from the user
    var N int
    fmt.Scan(&N)
    
    // Initialize the variable to keep track of the power of 10
    i := 1
    
    // Initialize the answer variable to accumulate the result
    ans := 0
    
    // Loop to calculate the contribution of each range of numbers defined by powers of 10
    for 10 ** i <= N {
        // Add the count of numbers in the current range (10^(i-1) to 10^i)
        ans += (10 ** i) - (10 ** (i - 1))
        
        // Increment i by 2 to move to the next range (skipping even powers)
        i += 2
    }
    
    // Add the count of numbers from the last valid power of 10 to N
    ans += max(0, N - 10 ** (i - 1) + 1)
    
    // Print the final result
    fmt.Println(ans)
}

// Function to calculate the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Entry point of the program
func main() {
    main()
}

