// Read two integers n and m from input
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Check if n is less than 1
if n < 1 {
    // If n is less than 1, check if m is also less than 1
    if m < 1 {
        // If both n and m are less than 1, print their values and exit
        fmt.Printf("%d %d\n", n, m)
        return
    }
    // If only n is less than 1 and m is greater than or equal to 1, print "Impossible"
    fmt.Println("Impossible")
    return
}

// If m is greater than n, calculate min and max values
if m > n {
    min := m  // Set min to m
    max := n + m - 1  // Calculate max based on n and m
    fmt.Printf("%d %d\n", min, max)  // Print the calculated min and max values
}

// If m is less than or equal to n, calculate min and max values
if m <= n {
    min := n  // Set min to n
    max := n + m - 1  // Calculate max based on n and m
    if m == 0 {
        max = n  // If m is 0, set max to n
    }
    fmt.Printf("%d %d\n", min, max)  // Print the calculated min and max values
}

