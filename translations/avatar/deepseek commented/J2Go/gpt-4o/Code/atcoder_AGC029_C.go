package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Main struct {
	n int      // Number of elements in the array
	a []int    // The array itself
	s map[int]int // Map to keep track of counts of elements
}

func main() {
	m := Main{}
	m.solve()
}

// Reads input values for n and the array a
func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &m.n)
	m.a = make([]int, m.n)
	for i := 0; i < m.n; i++ {
		fmt.Fscan(reader, &m.a[i])
	}
	m.s = make(map[int]int)
}

// Solves the problem by finding the maximum k such that the array can be partitioned into k non-empty subarrays
func (m *Main) solve() {
	m.set()
	ng := 0 // Lower bound for binary search
	ok := m.n // Upper bound for binary search
	for ok-ng > 1 {
		k := (ng + ok) / 2 // Midpoint of the current search range
		if m.isPossible(k) {
			ok = k // Adjust the upper bound if k is possible
		} else {
			ng = k // Adjust the lower bound if k is not possible
		}
	}
	fmt.Println(ok) // Print the result of the binary search
}

// Checks if it is possible to partition the array into k subarrays
func (m *Main) isPossible(k int) bool {
	m.s = make(map[int]int) // Clear the map for each new k
	current := 0             // Current index in the array
	for _, ai := range m.a {
		if ai <= current { // Check if the current element can be part of the previous subarray
			if k == 1 {
				return false // If k is 1, it's not possible to partition
			}
			for len(m.s) > 0 {
				keys := make([]int, 0, len(m.s))
				for key := range m.s {
					keys = append(keys, key)
				}
				sort.Ints(keys) // Sort keys to find the last key
				lastKey := keys[len(keys)-1]
				if lastKey >= ai {
					delete(m.s, lastKey) // Remove elements from the map that are greater than or equal to the current element
				} else {
					break
				}
			}
			p := ai - 1 // Start checking from the previous element
			for {
				if p < 0 {
					return false // If p goes below 0, it's not possible to partition
				}
				sp := m.s[p] + 1 // Get the count of p and add 1
				m.s[p] = sp      // Put the updated count back into the map
				if sp == k {     // If the count of p is equal to k
					delete(m.s, p) // Remove p from the map
					p--             // Move to the previous element
				} else {
					break // Break the loop if the count is not equal to k
				}
			}
		}
		current = ai // Update the current element
	}
	return true // Return true if it's possible to partition the array into k subarrays
}

// <END-OF-CODE>
