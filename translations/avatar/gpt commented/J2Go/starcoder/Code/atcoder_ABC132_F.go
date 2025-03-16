package main

import "fmt"

func main() {
	// Define the modulo constant for calculations to prevent overflow
	const mod = 1e9 + 7

	// Initialize scanner to read input values
	sc := bufio.NewScanner(os.Stdin)

	// Read the values of n and k from input
	var n, k int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ = strconv.Atoi(sc.Text())

	// Close the scanner as we no longer need input
	sc.Close()

	// Create a list to store the lengths of segments
	var len []int

	// Initialize the starting point for segment calculation
	l := 1

	// Calculate the lengths of segments based on the value of n
	for l <= n {
		// Calculate the right endpoint of the current segment
		r := n / (n / l)
		// Add the length of the current segment to the list
		len = append(len, r-l+1)
		// Move to the next segment
		l = r + 1
	}

	// Get the total number of segments calculated
	q := len(len)

	// Initialize a dynamic programming array to store results
	dp := make([]int, k*(q+1))

	// Fill the dp array for the first segment
	for j := 1; j <= q; j++ {
		dp[j] = len[j-1] + dp[j-1]
	}

	// Fill the dp array for subsequent segments
	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			// Calculate the number of ways to form segments
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*len[j-1]
			// Apply modulo to keep the value within limits
			dp[i*(q+1)+j] %= mod
		}
	}

	// Output the final result, which is the number of ways to form k segments
	fmt.Println(dp[k*(q+1)-1])
}

