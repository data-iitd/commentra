// Read input values N and X from the user
fmt.Scan(&N, &X)

// Define a function to perform calculations on the input list
func calc(x int) int {
	// Define a helper function to process the list y
	sub := func(y []int, debug bool) []int {
		// If debug mode is on, print the current state of y
		if debug {
			fmt.Println("D", y)
		}
		// Reduce the list y until it has only one element
		for len(y) > 1 {
			// Replace y with the second largest element of every three consecutive elements
			for i := 0; i < len(y)-2; i++ {
				y[i] = sort.IntSlice(y[i:i+3]).IntSlice()[1]
			}
			// If debug mode is on, print the current state of y
			if debug {
				fmt.Println("D", y)
			}
		}
		return y
	}

	// Call the helper function to process x
	y := sub([]int{x}, false)

	// If the final result is 2, perform additional processing
	if y[0] == 2 {
		// Placeholder for potential future logic
		sub([]int{x}, true)
		fmt.Println("=", x)
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

	// Handle the case where X is N * 2 - 2
	if X == N*2-2 {
		// Create a list xs with specific ranges
		xs := make([]int, N-1+X+2-N)
		for i := range xs {
			xs[i] = N - 1 + i
		}
		for i := range xs[N-1+X+2-N:] {
			xs[N-1+X+2-N+i] = i + 1
		}
	} else {
		// Create a list ys with specific ranges and then construct xs
		ys := make([]int, X-1+N*2-X-3)
		for i := range ys {
			ys[i] = i + 1
		}
		for i := range ys[X-1+N*2-X-3:] {
			ys[X-1+N*2-X-3+i] = N*2 - 2 - i
		}
		xs := make([]int, N-3+X-1+1)
		for i := range xs[:N-3] {
			xs[i] = ys[i]
		}
		xs[N-3] = X + 2
		xs[N-2] = X - 1
		xs[N-1] = X
		xs[N] = X + 1
		for i := range xs[N+1:] {
			xs[N+1+i] = ys[N-3+i]
		}
	}

	// Print each element in the final list xs
	for _, x := range xs {
		fmt.Println(x)
	}
}

