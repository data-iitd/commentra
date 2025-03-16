package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	fmt.Scan(&a)

	// Check if the sum of the elements in the list is divisible by the formula
	if sum(a)%(n*(n+1)/2) != 0 {
		fmt.Println("NO")
		return
	}

	// Calculate the average of the elements in the list
	k := sum(a) / (n * (n + 1) / 2)

	// Add the first element to the end of the list for simplification
	a = append(a, a[0])

	// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
	if sum(differences(a))%n != 0 || sum(ratios(a, k)) != n {
		fmt.Println("NO")
		return
	}

	// If all checks pass, print YES
	fmt.Println("YES")
}

func sum(a []int) int {
	var s int
	for _, v := range a {
		s += v
	}
	return s
}

func differences(a []int) []int {
	d := make([]int, len(a)-1)
	for i := range d {
		d[i] = (a[i+1] - a[i]) % len(a)
	}
	return d
}

func ratios(a []int, k int) []int {
	r := make([]int, len(a)-1)
	for i := range r {
		r[i] = (a[i+1] - a[i]) / k
	}
	return r
}

// 