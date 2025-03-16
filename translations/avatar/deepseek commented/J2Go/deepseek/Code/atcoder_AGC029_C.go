package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sort"
)

type Main struct {
	n int
	a []int
	s map[int]int
}

func main() {
	m := &Main{}
	m.solve()
}

// Reads input values for n and the array a
func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin)
	line, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	line = strings.TrimSpace(line)
	m.n, err = strconv.Atoi(line)
	if err != nil {
		fmt.Println("Error converting to integer:", err)
		return
	}
	line, err = reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	nums := strings.Split(strings.TrimSpace(line), " ")
	m.a = make([]int, m.n)
	for i := 0; i < m.n; i++ {
		m.a[i], err = strconv.Atoi(nums[i])
		if err != nil {
			fmt.Println("Error converting to integer:", err)
			return
		}
	}
	m.s = make(map[int]int)
}

// Solves the problem by finding the maximum k such that the array can be partitioned into k non-empty subarrays
func (m *Main) solve() {
	m.set()
	ng := 0 // Lower bound for binary search
	ok := m.n // Upper bound for binary search
	for ok - ng > 1 {
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
	current := 0 // Current index in the array
	for _, ai := range m.a {
		if ai <= current { // Check if the current element can be part of the previous subarray
			if k == 1 {
				return false // If k is 1, it's not possible to partition
			}
			for len(m.s) > 0 && m.lastKey(m.s) >= ai {
				delete(m.s, m.lastKey(m.s)) // Remove elements from the map that are greater than or equal to the current element
			}
			p := ai - 1 // Start checking from the previous element
			for {
				if p < 0 {
					return false // If p goes below 0, it's not possible to partition
				}
				sp := m.s[p] + 1 // Get or default the count of p and add 1
				m.s[p] = sp // Put the updated count back into the map
				if sp == k { // If the count of p is equal to k
					delete(m.s, p) // Remove p from the map
					p-- // Move to the previous element
				} else {
					break // Break the loop if the count is not equal to k
				}
			}
		}
		current = ai // Update the current element
	}
	return true // Return true if it's possible to partition the array into k subarrays
}

// Helper function to get the last key in a map
func (m *Main) lastKey(s map[int]int) int {
	keys := make([]int, 0, len(s))
	for k := range s {
		keys = append(keys, k)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(keys)))
	return keys[0]
}

