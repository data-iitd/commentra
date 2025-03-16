package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to calculate the binomial coefficient C(n, m)
func C(n, m int) int {
	res := 1 // Initialize result as 1
	// Calculate the numerator part of the binomial coefficient
	for i := m - n + 1; i <= m; i++ {
		res *= i // Multiply by i from (m-n+1) to m
	}
	// Calculate the denominator part of the binomial coefficient
	for i := 1; i <= n; i++ {
		res /= i // Divide by i from 1 to n
	}
	return res // Return the computed binomial coefficient
}

func main() {
	sc := bufio.NewScanner(os.Stdin) // Create a Scanner object for input
	n, p := 0, 0 // Declare variables for number of elements and parity
	k0, k1 := 0, 0 // Counter for even numbers, odd numbers
	ans := 1      // Initialize the answer as 1
	// Read the number of elements and the parity value
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	p, _ = strconv.Atoi(sc.Text())
	// Count the number of even and odd integers
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text()) // Read the next integer
		if x%2 == 1 {
			k1++ // Increment odd counter
		} else {
			k0++ // Increment even counter
		}
	}
	// Multiply the answer by 2 raised to the power of the number of even integers
	for i := 0; i < k0; i++ {
		ans *= 2 // Each even number contributes a factor of 2
	}
	// If p is 0, calculate combinations for even selections of odd integers
	if p == 0 {
		add := 0 // Initialize the sum for combinations
		// Sum the combinations of choosing even numbers of odd integers
		for i := 0; i <= k1; i += 2 {
			add += C(i, k1) // Add C(i, k1) for even i
		}
		ans *= add // Multiply the answer by the computed combinations
	} else { // If p is 1, calculate combinations for odd selections of odd integers
		add := 0 // Initialize the sum for combinations
		// Sum the combinations of choosing odd numbers of odd integers
		for i := 1; i <= k1; i += 2 {
			add += C(i, k1) // Add C(i, k1) for odd i
		}
		ans *= add // Multiply the answer by the computed combinations
	}
	fmt.Println(ans) // Output the final answer
}

