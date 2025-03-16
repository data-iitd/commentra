// Read the input from the user
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Calculate the quotient and remainder of n divided by m
q := n / m
r := n % m

// Initialize the a list with q repeated m times
a := make([]int, m)
for i := 0; i < m; i++ {
    a[i] = q
}

// Increment the corresponding elements in the a list for the remaining elements
for i := 0; i < r; i++ {
    a[i] += 1
}

// Print each element of the a list separated by a space
for i := 0; i < m; i++ {
    fmt.Printf("%d ", a[i])
}

