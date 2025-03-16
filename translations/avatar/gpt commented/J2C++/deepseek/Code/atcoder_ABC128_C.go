package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new instance of Main and invoke the run method
	main := new(Main)
	main.run()
}

type Main struct{}

func (m *Main) run() {
	// Initialize a Scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of elements N and the number of groups M
	sc.Scan()
	N := toInt(sc.Text())
	sc.Scan()
	M := toInt(sc.Text())

	// Create a slice to store bitwise representations for each element
	a := make([]int, N)

	// Initialize the slice with zeros for N elements
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	// Read M groups of integers and update the bitwise representation
	for i := 0; i < M; i++ {
		sc.Scan()
		k := toInt(sc.Text()) // Read the number of integers in the current group
		for j := 0; j < k; j++ {
			sc.Scan()
			s := toInt(sc.Text()) // Read the integer
			s-- // Convert to zero-based index
			// Update the bitwise representation for the element
			a[s] |= 1 << i
		}
	}

	// Read M integers to create a bitmask p
	p := 0
	for i := 0; i < M; i++ {
		sc.Scan()
		x := toInt(sc.Text()) // Read the integer
		p |= (x << i) // Update the bitmask p
	}

	// Initialize a counter for valid combinations
	ans := 0

	// Iterate through all possible subsets of N elements
	for s := 0; s < (1 << N); s++ {
		t := 0 // Initialize a temporary variable to store the XOR result
		for i := 0; i < N; i++ {
			// Check if the i-th element is included in the subset
			if (s>>i)&1 == 1 {
				// XOR the current element's bitwise representation
				t ^= a[i]
			}
		}
		// Check if the XOR result matches the bitmask p
		if p == t {
			ans++ // Increment the count of valid combinations
		}
	}

	// Output the total count of valid combinations
	fmt.Println(ans)
}

// Helper function to convert string to integer
func toInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

