package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the elements into a slice
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	// Initialize two slices to hold elements at even and odd indices
	a := []int{}
	b := []int{}

	// Distribute elements into slices based on their index (even or odd)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i]) // Append to slice 'a' if index is even
		} else {
			b = append(b, x[i]) // Append to slice 'b' if index is odd
		}
	}

	// Initialize counters for occurrences of elements in slices 'a' and 'b'
	cnta := make([]int, 100003) // 100002 + 1
	cntb := make([]int, 100003) // 100002 + 1

	// Variables to track the most frequent elements in slice 'a'
	vala, vala1, maxCnta, maxCnta1 := 0, 0, 0, 0

	// Count occurrences of each element in slice 'a'
	for _, i := range a {
		cnta[i]++
	}

	// Find the most frequent element in slice 'a'
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}

	// Find the second most frequent element in slice 'a'
	for _, i := range a {
		if maxCnta1 < cnta[i] && vala != i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	// Variables to track the most frequent elements in slice 'b'
	valb, valb1, maxCntb, maxCntb1 := 0, 0, 0, 0

	// Count occurrences of each element in slice 'b'
	for _, i := range b {
		cntb[i]++
	}

	// Find the most frequent element in slice 'b'
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}

	// Find the second most frequent element in slice 'b'
	for _, i := range b {
		if maxCntb1 < cntb[i] && valb != i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	// Check if the most frequent elements from both slices are different
	if valb != vala {
		res := 0
		// Count elements in 'a' that are not the most frequent element
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		// Count elements in 'b' that are not the most frequent element
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		// Print the total count of elements that are not the most frequent
		fmt.Println(res)
	} else {
		// Initialize counters for elements not equal to the most frequent elements
		resa, resb, resa1, resb1 := 0, 0, 0, 0

		// Count elements in 'a' that are not the most frequent and second most frequent
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}

		// Count elements in 'b' that are not the most frequent and second most frequent
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}

		// Print the minimum of the two possible results
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
