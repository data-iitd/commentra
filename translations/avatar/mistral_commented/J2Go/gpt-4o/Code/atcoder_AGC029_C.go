package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Main struct {
	n int         // Number of elements in the array 'a'
	a []int       // Array of integers
	s map[int]int // Map to store the count of each element
}

func main() {
	m := Main{} // Create an instance of Main struct
	m.solve()   // Call the solve method to find the solution
}

func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin) // Initialize BufferedReader for reading input
	fmt.Fscan(reader, &m.n)              // Read the first line containing the number of elements 'n'
	m.a = make([]int, m.n)               // Initialize the array 'a' with size 'n'
	for i := 0; i < m.n; i++ {           // Read the elements of the array 'a'
		fmt.Fscan(reader, &m.a[i])
	}
	m.s = make(map[int]int) // Initialize an empty map 's'
}

func (m *Main) solve() {
	m.set() // Call the set method to read the input
	ng := 0 // Initialize the lower bound of the search range
	ok := m.n // Initialize the upper bound of the search range

	for ok-ng > 1 { // Run the while loop until the search range is narrowed down to a single element
		k := (ng + ok) / 2 // Calculate the middle index of the search range
		if m.isPossible(k) { // If the middle index 'k' is a valid solution, update the upper bound
			ok = k
		} else { // Otherwise, update the lower bound
			ng = k
		}
	}

	fmt.Println(ok) // Print the solution
}

func (m *Main) isPossible(k int) bool {
	m.s = make(map[int]int) // Clear the map 's' before processing the new condition
	current := 0            // Initialize the current index in the array 'a'

	for _, ai := range m.a { // Iterate through each element in the array 'a'
		if ai <= current { // If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
			if k == 1 {
				return false // If 'k' is 1, return false as there is no possible solution
			}

			// Remove elements from the map that are greater than or equal to 'ai'
			for key := range m.s {
				if key >= ai {
					delete(m.s, key)
				}
			}

			p := ai - 1 // Calculate the previous index 'p'
			for {
				if p < 0 {
					return false // If 'p' is out of the array bounds, return false
				}

				sp := m.s[p] + 1 // Get the count of 'p' in the map or initialize it to 1
				m.s[p] = sp      // Update the count of 'p' in the map

				if sp == k { // If the count of 'p' is equal to 'k', remove it and move to the previous index
					delete(m.s, p)
					p--
				} else { // Otherwise, break the loop
					break
				}
			}
		}
		current = ai // Update the current index
	}

	return true // If all elements in the array 'a' are processed, return true as a valid solution is found
}
