package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read an integer n from input

	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i]) // Read a list of integers x from input
	}

	// Split the list x into two lists, a and b, based on their indices (even and odd)
	a := []int{}
	b := []int{}
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	// Initialize two slices to count the frequency of each element in a and b
	cnta := make([]int, 100003) // 100002 + 1
	cntb := make([]int, 100003) // 100002 + 1

	// Find the most frequent element in list a
	vala, vala1 := 0, 0
	maxCnta, maxCnta1 := 0, 0
	for _, i := range a {
		cnta[i]++
	}
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}
	for _, i := range a {
		if maxCnta1 < cnta[i] && vala != i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	// Find the most frequent element in list b
	valb, valb1 := 0, 0
	maxCntb, maxCntb1 := 0, 0
	for _, i := range b {
		cntb[i]++
	}
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}
	for _, i := range b {
		if maxCntb1 < cntb[i] && valb != i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	// Compare the most frequent elements of a and b
	if valb != vala {
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
