
// Function to solve a single test case
func solveCase() {

	// Read input: number of rows and columns
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize a 2D array 'count' of size n x n with all elements as 0
	count := make([][]int, n)
	for i := range count {
		count[i] = make([]int, n)
	}

	// Variable to store the answer
	ans := -1

	// Iterate through each query
	for k := 0; k < m; k++ {

		// Read input: x and y for the current query
		var x, y int
		fmt.Scan(&x, &y)

		// Adjust input for array indexing
		x--
		y--

		// Check if there is a group of 3x3 cells with count equal to 9
		found := false
		for i := x - 2; i <= x+1; i++ {
			for j := y - 2; j <= y+1; j++ {
				// Check if the cell is within the grid boundaries
				if i >= 0 && i < n && j >= 0 && j < n {
					// Increment the count of the current cell
					count[i][j]++
					// If the count becomes 9, then we have found the group
					if count[i][j] == 9 {
						found = true
						break
					}
				}
			}
			if found {
				break
			}
		}

		// If a group of 3x3 cells with count equal to 9 is found, then update the answer
		if found {
			ans = k + 1
			break
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Call the function to solve the test case
solveCase()

