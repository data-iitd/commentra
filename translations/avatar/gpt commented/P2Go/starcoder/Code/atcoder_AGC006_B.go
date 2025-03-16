// Read input values N and X from the user
var N, X int
fmt.Scanf("%d %d", &N, &X)

// Define a function to perform calculations on the input list
func calc(x []int) int {
	// Define a helper function to process the list y
	func sub(y []int) []int {
		// Reduce the list y until it has only one element
		for len(y) > 1 {
			// Replace y with the second largest element of every three consecutive elements
			y = []int{sorted(y[i:i+3])[1] for i := range len(y)-2}
		}
		return y
	}

	// Call the helper function to process x
	y := sub(x)

	// If the final result is 2, perform additional processing
	if y[0] == 2 {
		// Placeholder for potential future logic
		sub(x)  // Call sub with debug mode on
		fmt.Println("=", x)  // Print the original list x
	}

	// Return the final processed value
	return y[0]
}

// Check specific conditions based on the value of X
if X == 1 || X == N*2-1 {
	// If X is at the boundaries, print "No"
	fmt.Println("No")
} else {
	// If X is within the valid range, print "Yes"
	fmt.Println("Yes")

	// Handle the case where X is N*2-2
	if X == N*2-2 {
		// Create a list xs with specific ranges
		xs := []int{i for i := range N-1:X+2} + []int{i for i := range 1:N-1}
	} else {
		// Create a list ys with specific ranges and then construct xs
		ys := []int{i for i := range 1:X-1} + []int{i for i := range X+3:N*2}
		xs := ys[:N-3] + []int{X+2, X-1, X, X+1} + ys[N-3:]
	}

	// Print each element in the final list xs
	for _, x := range xs {
		fmt.Println(x)
}

