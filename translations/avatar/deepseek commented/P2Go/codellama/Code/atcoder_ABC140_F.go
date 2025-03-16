
package main

import (
	"fmt"
	"sort"
)

// Function to read an integer from standard input
func I() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a list of integers from standard input
func LI() []int {
	var n int
	fmt.Scan(&n)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	return s
}

func main() {
	// Read the number of elements N
	N := I()

	// Read the list of integers S, sort them in descending order
	S := LI()
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	// Initialize a flag array to keep track of used elements
	flag := make([]bool, len(S))

	// Initialize the current list with the first element of S
	cur := []int{S[0]}
	flag[0] = false

	// Loop through N times
	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)

		// Iterate over the elements of S
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				// Add the element to cur, set its flag to False, and increment j
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}

		// If no such element is found, return "No"
		if j == 0 {
			fmt.Println("No")
			return
		}

		// Sort cur in descending order
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}

	// Return "Yes" if the condition is satisfied
	fmt.Println("Yes")
}

