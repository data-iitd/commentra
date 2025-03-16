package main

import (
	"fmt"
	"math"
)

// Define a constant for the value of PI
const PI = 3.14159265358979

// Define a type alias for long long
type ll int64

// Macro to simplify loop creation
func rep(i int, n int) {
	for ; i < n; i++ {
	}
}

func main() {
	// Declare variables to hold the number of groups
	var n, m int

	// Input the number of groups n and m
	fmt.Scanf("%d %d\n", &n, &m)

	// Initialize the answer variable to store the total pairs
	var ans int

	// Calculate the number of pairs within group n
	// The formula n*(n-1)/2 gives the number of ways to choose 2 from n
	ans += n * (n - 1) / 2

	// Calculate the number of pairs within group m
	// Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
	ans += m * (m - 1) / 2

	// Output the total number of pairs
	fmt.Println(ans)
}

