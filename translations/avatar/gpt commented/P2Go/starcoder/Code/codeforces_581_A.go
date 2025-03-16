// Read two integers from input and unpack them into variables a and b
var a, b int
fmt.Scanf("%d %d", &a, &b)

// Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
// Print the minimum value and the calculated half difference
fmt.Printf("%d %d", min(a, b), (max(a, b) - min(a, b)) / 2)

