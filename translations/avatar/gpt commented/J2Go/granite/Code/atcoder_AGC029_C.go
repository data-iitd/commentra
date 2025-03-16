
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	n int
	a []int
	s map[int]int
)

func main() {
	// Create an instance of Main and invoke the solve method
	m := Main{}
	m.solve()
}

type Main struct{}

func (m *Main) set() {
	// Read input values and initialize variables
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text()) // Read the number of elements
	// Read the array elements and convert them to an integer array
	a = make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
	}
	s = make(map[int]int) // Initialize the map
}

func (m *Main) solve() {
	// Main logic to find the maximum k using binary search
	m.set() // Initialize input values
	ng := 0 // Lower bound for binary search
	ok := n // Upper bound for binary search

	// Perform binary search to find the maximum k
	for ok-ng > 1 {
		k := (ng + ok) / 2 // Calculate mid-point
		// Check if it is possible to achieve the current k
		if m.isPossible(k) {
			ok = k // If possible, adjust upper bound
		} else {
			ng = k // If not possible, adjust lower bound
		}
	}
	// Output the result
	fmt.Println(ok)
}

func (m *Main) isPossible(k int) bool {
	// Check if it is possible to achieve the given k
	s = make(map[int]int) // Clear the map for new calculations
	current := 0 // Initialize current value

	// Iterate through each element in the array
	for _, ai := range a {
		// If the current element is less than or equal to the current value
		if ai <= current {
			// If k is 1, return false as we cannot have duplicates
			if k == 1 {
				return false
			}

			// Remove elements from the map that are greater than or equal to ai
			for p := ai - 1; ; p-- {
				if p < 0 {
					return false
				}
				// Get the count of p from the map and increment it
				sp := s[p] + 1
				s[p] = sp // Update the map with the new count

				// If the count reaches k, remove p from the map and decrement p
				if sp == k {
					delete(s, p)
					break
				}
			}
		}
		current = ai // Update current to the current element
	}
	return true // Return true if the condition is satisfied
}

// END-OF-CODE