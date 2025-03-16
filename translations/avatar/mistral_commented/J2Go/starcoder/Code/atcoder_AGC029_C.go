
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function
func main() {
	m := new(Main) // Create an instance of Main class
	m.solve()     // Call the solve method to find the solution
}

// Main structure
type Main struct {
	n int
	a []int
	s map[int]int
}

// Set function
func (m *Main) set() {
	br := bufio.NewReader(os.Stdin) // Initialize BufferedReader for reading input
	line, _ := br.ReadString('\n')   // Read the first line containing the number of elements 'n'
	m.n, _ = strconv.Atoi(strings.TrimSpace(line)) // Parse the string to integer 'n'
	line, _ = br.ReadString('\n') // Read the second line containing the elements of the array 'a'
	m.a = make([]int, m.n)
	for i, v := range strings.Fields(strings.TrimSpace(line)) {
		m.a[i], _ = strconv.Atoi(v)
	}
	m.s = make(map[int]int) // Initialize an empty map's'
}

// Solve function
func (m *Main) solve() {
	m.set() // Call the set method to read the input
	ng := 0
	ok := m.n
	for ok-ng > 1 {
		k := (ng + ok) / 2
		if m.isPossible(k) {
			ok = k
		} else {
			ng = k
		}
	}
	fmt.Println(ok)
}

// IsPossible function
func (m *Main) isPossible(k int) bool {
	m.s = make(map[int]int)
	current := 0
	for _, ai := range m.a {
		if ai <= current {
			if k == 1 {
				return false
			}
			for p := ai - 1; ; p-- {
				if p < 0 {
					return false
				}
				sp := m.s[p] + 1
				m.s[p] = sp
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

