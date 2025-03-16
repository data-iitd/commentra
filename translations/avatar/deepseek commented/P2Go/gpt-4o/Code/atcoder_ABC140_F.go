package main

import (
	"fmt"
	"sort"
)

// Function to read an integer from standard input
func I() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from standard input
func LI() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

func main() {
	// Read the number of elements N
	N := I()

	// Read the list of integers S
	S := LI()

	// Sort S in descending order
	sort.Slice(S, func(i, j int) bool {
		return S[i] > S[j]
	})

	// Initialize a flag array to keep track of used elements
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

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
				// Add the element to cur, set its flag to false, and increment j
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
		sort.Slice(cur, func(i, j int) bool {
			return cur[i] > cur[j]
		})
	}

	// Return "Yes" if the condition is satisfied
	fmt.Println("Yes")
}

// <END-OF-CODE>
