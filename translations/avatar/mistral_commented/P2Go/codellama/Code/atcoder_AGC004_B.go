// Function to take input and convert it into list of integers
func main() {
	// Take input of number of test cases and number of elements in each test case
	var n, x int
	fmt.Scan(&n, &x)

	// Initialize an empty list 'a' to store the given elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize a 2D list 'b' of size n x n with None values
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
	}

	// Iterate through each row of list 'a'
	for i := 0; i < n; i++ {
		// Initialize a variable 'm' to store the minimum element in the current row
		m := a[i]

		// Iterate through each column of list 'b'
		for j := 0; j < n; j++ {
			// Calculate the index 'k' based on the current row and column indices
			k := i - j

			// If the index 'k' is negative, add the size of list 'n' to make it positive
			if k < 0 {
				k += n
			}

			// Update the minimum value of 'm' with the minimum value of 'a[k]'
			m = min(m, a[k])

			// Update the corresponding cell in list 'b' with the minimum value of 'm'
			b[j][i] = m
		}
	}

	// Initialize a variable 'm' with a large value to keep track of the minimum sum
	m := 1000000000000000000

	// Iterate through each row of list 'b'
	for i, j := range b {
		// Calculate the sum of elements in the current row and add 'x * i' to it
		sum_row := sum(j) + x*i

		// Update the minimum value of 'm' with the sum of the current row
		m = min(m, sum_row)
	}

	// Print the minimum sum
	fmt.Println(m)
}

// Function to calculate the sum of elements in a list
func sum(a []int) int {
	// Initialize a variable 's' to store the sum
	s := 0

	// Iterate through each element of list 'a'
	for _, i := range a {
		// Add the current element to the sum
		s += i
	}

	// Return the sum
	return s
}

// Function to calculate the minimum of two integers
func min(a, b int) int {
	// Return the minimum of 'a' and 'b'
	if a < b {
		return a
	}
	return b
}

