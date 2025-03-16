package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take the number of test cases as input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 't' with 0 as the first element and followed by the given input list
	t := make([]int, n+1)
	t[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&t[i])
	}

	// Initialize a slice 'a' with 0 as the first element and followed by the given input list
	a := make([]int, n+1)
	a[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize empty slices 'ans' and 'cnt'
	ans := []int{}
	cnt := make([]int, n+1)

	// Iterate through each element in slice 'a' and increment the count of its corresponding index in slice 'cnt'
	for _, value := range a {
		cnt[value]++
	}

	// Iterate through each index from 1 to n
	for i := 1; i <= n; i++ {
		// If the current index in slice 't' is 1
		if t[i] == 1 {
			// Initialize an empty slice 'crt' to store the current sequence
			crt := []int{i}
			// Get the current element in slice 'a'
			x := a[i]
			// Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			// If the length of the current sequence is greater than the length of the current answer sequence
			if len(crt) > len(ans) {
				// Update the answer sequence with the current sequence
				ans = make([]int, len(crt))
				copy(ans, crt)
			}
		}
	}

	// Reverse the order of elements in the answer sequence
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	// Print the length of the answer sequence
	fmt.Println(len(ans))
	// Print the answer sequence with each element separated by a space
	fmt.Println(strings.Join(intSliceToStringSlice(ans), " "))
}

// Helper function to convert a slice of integers to a slice of strings
func intSliceToStringSlice(ints []int) []string {
	strs := make([]string, len(ints))
	for i, v := range ints {
		strs[i] = fmt.Sprintf("%d", v)
	}
	return strs
}
