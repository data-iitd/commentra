// Define a helper function 'twos_in_factorial' to count the number of twos in the factorial of a given number
func twos_in_factorial(n int) int {
	// Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
	return n - bits.OnesCount(uint(n))
}

// Define a helper function 'parity_of_nCr' to check if the index 'i' has odd parity in the combination 'nCr'
func parity_of_nCr(n, i int) bool {
	// Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
	f := twos_in_factorial
	// Return True if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
	return f(n) - f(n - i) - f(i) > 0
}

// Check if the input is valid and process the given problem
func main() {
	// Read the input values from the standard input
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := range nums {
		fmt.Scan(&nums[i])
		nums[i]--
	}

	// Initialize a flag to indicate if there is no '1' in the list of numbers
	no_one := true

	// If there is no '1' in the list of numbers, then replace each number by half of it
	if !hasOne(nums) {
		for i := range nums {
			nums[i] /= 2
		}
		no_one = false
	}

	// Initialize a flag to indicate if the result is odd
	is_odd := false

	// Iterate through each number in the list and check if it satisfies the given condition
	for i, num := range nums {
		// Skip the number if it doesn't satisfy the parity condition
		if !parity_of_nCr(n-1, i) && num&1 == 1 {
			// Toggle the 'is_odd' flag
			is_odd = !is_odd
		}
	}

	// Print the result based on the value of the 'is_odd' flag
	if !is_odd {
		fmt.Println(0)
	} else {
		// If there is no '1' in the list of numbers, then print the result with the 'no_one' flag shifted to the left
		fmt.Println(1 << no_one)
	}
}

// Define a helper function 'hasOne' to check if the input list contains the number '1'
func hasOne(nums []int) bool {
	for _, num := range nums {
		if num == 1 {
			return true
		}
	}
	return false
}

