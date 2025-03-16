package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Reading the values of n and m from input
	n, m := readInts()

	// Reading m lists of integers, each containing values after the first element
	li := readLists(m)

	// Reading a tuple p from input
	p := readTuple()

	// Creating a set q that contains all unique elements from the lists in li
	q := make(map[int]bool)
	for _, u := range li {
		for _, v := range u {
			q[v] = true
		}
	}

	// Creating a set r that contains all integers from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}

	// Finding the set of values v that are in r but not in q
	v := make(map[int]bool)
	for i := 1; i <= n; i++ {
		if !q[i] {
			v[i] = true
		}
	}

	// Initializing the answer variable to count valid combinations
	ans := 0

	// Iterating over all possible sizes of combinations from the set q
	for i := 0; i <= len(q); i++ {
		// Generating combinations of size i from the set q
		for s := range combinations(q, i) {
			// Checking each list in li against the corresponding value in p
			for u, w := range li {
				s := make(map[int]bool) // Converting the combination to a set for intersection
				// If the count of common elements is odd and does not match w, break
				if len(intersection(s, u))%2 != w {
					break
				}
			}
			// If all checks passed, increment the answer by 2 raised to the power of the size of v
			ans += int(math.Pow(2, float64(len(v))))
		}
	}

	// Printing the final answer
	fmt.Println(ans)
}

// readInts reads a line of integers from input and returns them as a slice
func readInts() (int, int) {
	var n, m int
	fmt.Scan(&n, &m)
	return n, m
}

// readLists reads m lists of integers from input and returns them as a slice of slices
func readLists(m int) [][]int {
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		li[i] = readIntsList()
	}
	return li
}

// readIntsList reads a list of integers from input and returns them as a slice
func readIntsList() []int {
	var n int
	fmt.Scan(&n)
	li := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&li[i])
	}
	return li
}

// readTuple reads a tuple of integers from input and returns them as a slice
func readTuple() []int {
	var n int
	fmt.Scan(&n)
	t := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&t[i])
	}
	return t
}

// combinations generates all possible combinations of size r from a set s
func combinations(s map[int]bool, r int) map[int]bool {
	c := make(map[int]bool)
	for i := 0; i < len(s); i++ {
		for j := i + 1; j < len(s); j++ {
			c[i] = true
			c[j] = true
		}
	}
	return c
}

// intersection returns the intersection of two sets
func intersection(s, t map[int]bool) map[int]bool {
	i := make(map[int]bool)
	for k := range s {
		if t[k] {
			i[k] = true
		}
	}
	return i
}

// END-OF-CODE
