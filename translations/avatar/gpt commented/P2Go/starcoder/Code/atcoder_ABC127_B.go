// Read input values for r, D, and x from the user
r, D, x := 0, 0, 0
fmt.Scanf("%d %d %d", &r, &D, &x)

// Iterate over a range of values from 2 to 11 (inclusive)
for i := 2; i <= 11; i++ {
    // Calculate and print the result based on the formula
    // The formula computes a value using the current iteration index i,
    // the input values r, D, and x, and prints the integer result
    fmt.Printf("%d\n", int((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r)))
}

