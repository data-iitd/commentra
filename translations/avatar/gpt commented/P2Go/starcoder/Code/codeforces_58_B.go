// Read an integer input from the user
var n int
fmt.Scanf("%d", &n)

// Iterate from n down to 1
for i := n; i > 0; i-- {
    // Check if i is a divisor of n
    if n%i == 0 {
        // Update n to the current divisor i
        n = i
        // Print the divisor followed by a space
        fmt.Printf("%d ", i)
    }
}

