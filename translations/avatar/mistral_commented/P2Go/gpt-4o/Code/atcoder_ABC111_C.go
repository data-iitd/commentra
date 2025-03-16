package main

import (
	"fmt"
)

func main() {
	// Take the number of elements in the list from user input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'x' to store the input elements
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}

	// Initialize two slices 'a' and 'b' to store even and odd elements respectively
	var a, b []int

	// Iterate through the slice 'x' and append even and odd elements to their respective slices
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	// Initialize two slices 'cnta' and 'cntb' of size 100002+1 to store the count of each element in slices 'a' and 'b' respectively
	cnta := make([]int, 100002+1)
	cntb := make([]int, 100002+1)

	// Initialize variables to store the elements with maximum count in slices 'a' and 'b' respectively
	var vala, valb int
	var maxCnta, maxCntb int

	// Iterate through slice 'a' and update the count of each element in 'cnta'
	for _, i := range a {
		cnta[i]++
	}

	// Find the element with maximum count in slice 'a' and update 'vala' and 'maxCnta'
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}

	// Find the second element with maximum count in slice 'a' (different from 'vala')
	var vala1, maxCnta1 int
	for _, i := range a {
		if maxCnta1 < cnta[i] && i != vala {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	// Similar logic for slice 'b'
	for _, i := range b {
		cntb[i]++
	}

	// Find the element with maximum count in slice 'b' and update 'valb' and 'maxCntb'
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}

	// Find the second element with maximum count in slice 'b' (different from 'valb')
	var valb1, maxCntb1 int
	for _, i := range b {
		if maxCntb1 < cntb[i] && i != valb {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	// Check if 'vala' and 'valb' are the same or not
	if valb != vala {
		// If they are not the same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
		res := 0
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		fmt.Println(res)
	} else {
		// If 'vala' and 'valb' are the same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in slice 'a' and slice 'b' respectively
		// and print the minimum of these two sums
		resa, resb, resa1, resb1 := 0, 0, 0, 0
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}
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
