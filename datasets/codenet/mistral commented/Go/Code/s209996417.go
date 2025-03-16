// This is the main function where the program starts execution
func main() {
	// Initialize two float64 variables n and k to read input values
	var n float64
	var k float64

	// Read input values n and k from the standard input using fmt.Scan()
	fmt.Scan(&n, &k)

	// Calculate the number of digits required in k-base representation of number n
	// This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)

	// Initialize a float64 variable x with initial value 0.0
	var x float64 = 0.0

	// Use a for loop to find the smallest power of k that satisfies the condition
	for {
		// Calculate the lower and upper bounds of the current power of k
		under := math.Pow(k, x)
		upper := math.Pow(k, x+1)

		// Check if the number n lies between under and upper bounds
		if under <= n && n < upper {
			// If the condition is satisfied, print the result (number of digits) and exit the function
			fmt.Println(x + 1)
			return
		}

		// If the condition is not satisfied, increment the value of x and continue the loop
		x++
	}
}

// "