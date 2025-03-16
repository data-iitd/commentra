// Read input values for n and k
fmt.Scan(&n, &k)

// Read the list of integers M from input
M := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scan(&M[i])
}

// Initialize a variable m to zero (not used in the current logic)
m := 0

// Outer loop to iterate over each index j in the range of n
for j := 0; j < n; j++ {
    // Inner loop to find the first index p where M[p] is zero
    for p := 0; p < n; p++ {
        if (0 == M[p]) {
            // Print the index (1-based) where M[p] is zero
            fmt.Printf("%d ", p + 1)
            break
        }
    }

    // Decrease the values in M from the start up to p + 1 - k
    for l := 0; l < p + 1 - k; l++ {
        M[l] -= 1
    }

    // Decrease the value at index p in M
    M[p] -= 1
}

// End of code
