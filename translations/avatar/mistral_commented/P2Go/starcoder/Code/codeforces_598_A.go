#######
# Code
#######

// Take an integer input from the user
t := 0
fmt.Scanf("%d", &t)

// Define a function named'solve' that takes an integer argument 'n'
func solve(n int) int {
    // Calculate the sum of first 'n' natural numbers using the formula
    s := (1 + n) * n / 2
    
    // Initialize the variable 't' with the value 1
    t := 1
    
    // Run the while loop as long as 't' is less than or equal to 'n'
    for t <= n {
        // Subtract the contribution of 't' from the sum's'
        s -= 2 * t
        
        // Multiply the value of 't' by 2 and update its value
        t *= 2
    }
    
    // Return the final value of's'
    return s
}

// Run the loop 't' number of times
for i := 0; i < t; i++ {
    // Take an integer input from the user for 'n'
    n := 0
    fmt.Scanf("%d", &n)
    
    // Call the'solve' function with the input 'n' and print the result
    fmt.Printf("%d\n", solve(n))
}

