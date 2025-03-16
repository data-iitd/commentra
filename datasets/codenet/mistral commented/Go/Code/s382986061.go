package main

import "fmt"

// Initialize variables
var N, K int
var d, a int

func main() {
	// Read input values for N and K
	fmt.Scan(&N, &K)

	// Initialize an associative array (map) named as to store the frequency of each number
	as := make(map[int]int)

	// Initialize all elements of the map with zero frequency
	for i := 1; i <= N; i++ {
		as[i] = 0
	}

	// Read K queries and process them
	for i := 0; i < K; i++ {
		// Read the length of the query
		fmt.Scan(&d)

		// Read the numbers in the query and increment their frequency in the map
		for j := 0; j < d; j++ {
			fmt.Scan(&a)
			as[a]++
		}
	}

	// Initialize a variable named ans to store the answer
	ans := 0

	// Iterate through the map and check if the frequency of any number is zero
	// If yes, increment the value of ans
	for _, v := range as {
		if v == 0 {
			ans++
		}
		// Print the final answer
	}

	// Print the final answer
	fmt.Println(ans)

	// End of the code
}