package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create an instance of Main and invoke the run method
	main := Main{}
	main.run()
}

// Main is the main structure
type Main struct {
}

// Run the main code
func (m *Main) run() {
	// Initialize a Scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements N and the number of groups M
	N, _ := strconv.Atoi(sc.Text())
	M, _ := strconv.Atoi(sc.Text())

	// Create an array to store bitwise representations for each element
	a := make([]int, N)

	// Initialize the array with zeros for N elements
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	// Read M groups of integers and update the bitwise representation
	for i := 0; i < M; i++ {
		k, _ := strconv.Atoi(sc.Text()) // Read the number of integers in the current group
		for j := 0; j < k; j++ {
			s, _ := strconv.Atoi(sc.Text()) // Read the integer
			s-- // Convert to zero-based index
			// Update the bitwise representation for the element
			a[s] = a[s] | (1 << i)
		}
	}

	// Read M integers to create a bitmask p
	p := 0
	for i := 0; i < M; i++ {
		x, _ := strconv.Atoi(sc.Text()) // Read the integer
		p = p | (x << i) // Update the bitmask p
	}

	// Initialize a counter for valid combinations
	ans := 0

	// Iterate through all possible subsets of N elements
	for s := 0; s < (1 << N); s++ {
		t := 0 // Initialize a temporary variable to store the XOR result
		for i := 0; i < N; i++ {
			// Check if the i-th element is included in the subset
			if ((s >> i) & 1) == 1 {
				// XOR the current element's bitwise representation
				t = t ^ a[i]
			}
		}
		// Check if the XOR result matches the bitmask p
		if p == t {
			ans++ // Increment the count of valid combinations
		}
	}

	// Output the total count of valid combinations
	fmt.Println(ans)

	// Close the scanner to free resources
	sc.Close()
}

