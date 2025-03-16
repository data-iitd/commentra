// Import the math module for mathematical functions
// Define a function to read an integer input from the user
func nextInt() int {
	// Read an integer input from the user and convert it to an integer
	var n int
	fmt.Scan(&n)
	return n
}
// Define a function to read a list of integers from the user
func nextInts() []int {
	// Read a list of integers from the user and convert each element to an integer
	var n []int
	fmt.Scan(&n)
	return n
}
// Read an integer `n` from the user
n := nextInt()
// Initialize a variable `t` to zero
t := 0
// Iterate through the range of integers from 0 to n-1
for i := 0; i < n; i++ {
	// Check if the index i is odd
	if i+1&1 == 1 {
		// If it is odd, increment the variable t by 1
		t++
	}
}
// Print the result t/n as the output
fmt.Println(float64(t) / float64(n))


