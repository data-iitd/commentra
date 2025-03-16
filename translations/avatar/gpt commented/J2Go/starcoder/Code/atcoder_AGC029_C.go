package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main structure
type Main struct {
	n int
	a []int
	s map[int]int
}

// NewMain creates a new Main structure
func NewMain() *Main {
	return &Main{
		n: 0,
		a: make([]int, 0),
		s: make(map[int]int),
	}
}

// Set input values
func (m *Main) set() {
	// Read input values
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &m.n)
	m.a = make([]int, m.n)
	for i := 0; i < m.n; i++ {
		fmt.Fscan(reader, &m.a[i])
	}
}

// Solve the problem
func (m *Main) solve() {
	// Main logic to find the maximum k using binary search
	m.set() // Initialize input values
	ng := 0
	ok := m.n

	// Perform binary search to find the maximum k
	for ok-ng > 1 {
		k := (ng + ok) / 2
		if m.isPossible(k) {
			ok = k
		} else {
			ng = k
		}
	}
	// Output the result
	fmt.Println(ok)
}

// Check if it is possible to achieve the given k
func (m *Main) isPossible(k int) bool {
	m.s = make(map[int]int)
	current := 0

	// Iterate through each element in the array
	for _, ai := range m.a {
		// If the current element is less than or equal to the current value
		if ai <= current {
			// If k is 1, return false as we cannot have duplicates
			if k == 1 {
				return false
			}

			// Remove elements from TreeMap that are greater than or equal to ai
			for p := range m.s {
				if p >= ai {
					delete(m.s, p)
				}
			}

			p := ai - 1
			for {
				// If p is less than 0, return false
				if p < 0 {
					return false
				}

				// Get the count of p from TreeMap and increment it
				sp := m.s[p] + 1
				m.s[p] = sp

				// If the count reaches k, remove p from TreeMap and decrement p
				if sp == k {
					delete(m.s, p)
					p--
				} else {
					break
				}
			}
		}
		current = ai
	}
	return true
}

// Main function
func main() {
	// Create an instance of Main and invoke the solve method
	m := NewMain()
	m.solve()
}

