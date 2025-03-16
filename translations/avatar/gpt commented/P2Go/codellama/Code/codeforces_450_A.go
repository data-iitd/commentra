package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and m from input, where n is the number of elements and m is the divisor
	n, m := readTwoInts()

	// Read a list of n integers from input
	l := readList(n)

	// Initialize an empty list to store the results after processing the input list
	l2 := make([]int, 0)

	// Iterate through each element in the input list
	for _, i := range l {
		// If the current element is divisible by m, append the quotient to l2
		if i%m == 0 {
			l2 = append(l2, i/m)
		}
		// If the current element is not divisible by m, append the quotient plus one to l2
		else {
			l2 = append(l2, i/m+1)
		}
	}

	// Find the maximum value in the processed list l2
	mx := max(l2)

	// Iterate through the range of n to find the index of the maximum value in l2
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			ind := i // Store the index of the maximum value

			// Print the index of the maximum value (1-based index)
			fmt.Println(ind + 1)
			return
		}
	}
}

func readTwoInts() (int, int) {
	var n, m int
	fmt.Scan(&n, &m)
	return n, m
}

func readList(n int) []int {
	var l []int
	fmt.Scan(&l)
	return l
}

func max(l []int) int {
	mx := l[0]
	for _, i := range l {
		if i > mx {
			mx = i
		}
	}
	return mx
}

