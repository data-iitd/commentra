
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements N and the number of groups M
	N, _ := fmt.Fscanf(reader, "%d %d\n", &N, &M)

	// Create an array to store bitwise representations for each element
	a := make([]int, N)

	// Initialize the array with zeros for N elements
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	// Read M groups of integers and update the bitwise representation
	for i := 0; i < M; i++ {
		k, _ := fmt.Fscanf(reader, "%d", &k)
		for j := 0; j < k; j++ {
			s, _ := fmt.Fscanf(reader, "%d", &s)
			s-- // Convert to zero-based index
			// Update the bitwise representation for the element
			a[s] |= (1 << i)
		}
	}

	// Read M integers to create a bitmask p
	p := 0
	for i := 0; i < M; i++ {
		x, _ := fmt.Fscanf(reader, "%d", &x)
		p |= (x << i)
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

