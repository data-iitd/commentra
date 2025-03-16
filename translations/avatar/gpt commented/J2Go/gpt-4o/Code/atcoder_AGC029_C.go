package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Main struct {
	n int         // Number of elements in the array
	a []int       // Array to store the input integers
	s map[int]int // Map to keep track of counts of integers
}

func main() {
	m := Main{}
	m.solve()
}

func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &m.n) // Read the number of elements
	m.a = make([]int, m.n)   // Initialize the array
	for i := 0; i < m.n; i++ {
		fmt.Fscan(reader, &m.a[i]) // Read the array elements
	}
	m.s = make(map[int]int) // Initialize the map
}

func (m *Main) solve() {
	m.set() // Initialize input values
	ng := 0  // Lower bound for binary search
	ok := m.n // Upper bound for binary search

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
	m.s = make(map[int]int) // Clear the map for new calculations
	current := 0             // Initialize current value

	// Iterate through each element in the array
	for _, ai := range m.a {
		// If the current element is less than or equal to the current value
		if ai <= current {
			// If k is 1, return false as we cannot have duplicates
			if k == 1 {
				return false
			}

			// Remove elements from map that are greater than or equal to ai
			for key := range m.s {
				if key >= ai {
					delete(m.s, key) // Remove the entry
				}
			}

			p := ai - 1 // Start checking from the previous number
			for {
				// If p is less than 0, return false
				if p < 0 {
					return false
				}

				// Get the count of p from map and increment it
				sp := m.s[p] + 1
				m.s[p] = sp // Update the map with the new count

				// If the count reaches k, remove p from map and decrement p
				if sp == k {
					delete(m.s, p)
					p--
				} else {
					break // Exit the loop if count is less than k
				}
			}
		}
		current = ai // Update current to the current element
	}
	return true // Return true if the condition is satisfied
}

// <END-OF-CODE>
