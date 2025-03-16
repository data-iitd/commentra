package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize two arrays to hold the input values and their remainders
	a := make([]int, 5)
	r := make([]int, 5)

	// Create a map to store the required values for adjustment
	m := make(map[int]int)

	// Read 5 integers from the user and calculate their remainders
	for i := 0; i < 5; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		r[i] = a[i] % 10

		// Initialize adjustment value
		b := 10
		// If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
		if r[i]!= 0 {
			b = 10 - r[i]
			// Store the adjustment and the original value in the map
			m[b] = a[i]
		}
	}

	// Initialize the answer variable to accumulate the result
	ans := 0

	// If no adjustments are needed (map is empty), sum all input values
	if len(m) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	// Get the last key (largest adjustment) from the map
	last := m[max(m)]
	idx := 0

	// Find the index of the last value in the original array
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
		}
	}

	// Calculate the final answer by adding values, adjusting as necessary
	for i := 0; i < 5; i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}

	// Add the last value to the answer
	ans += last

	// Print the final calculated answer
	fmt.Println(ans)
}

// max returns the largest key in the map
func max(m map[int]int) int {
	var max int
	for k := range m {
		if k > max {
			max = k
		}
	}
	return max
}

