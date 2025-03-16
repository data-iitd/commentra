package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Taking an integer input `n` which represents the number of elements.

	t := make([]int, n+1)
	t[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&t[i]) // Taking a list of integers `t` as input.
	}

	a := make([]int, n+1)
	a[0] = 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i]) // Taking another list of integers `a` as input.
	}

	ans := []int{}
	cnt := make([]int, n+1) // Initializing a list `cnt` with zeros.

	// Counting the occurrences of each element in `a` and storing them in `cnt`.
	for _, value := range a {
		cnt[value]++
	}

	// Iterating over the range from 1 to `n` to find cycles starting from each element.
	for i := 1; i <= n; i++ {
		if t[i] == 1 { // Checking if `t[i]` is 1, indicating the start of a potential cycle.
			crt := []int{i} // Starting a list `crt` with `i`.
			x := a[i] // Initializing `x` with the value at index `i` in `a`.
			// Finding the cycle by following the `a` list until reaching an element whose count is not 1.
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			// Updating `ans` if the length of `crt` is greater than the length of `ans`.
			if len(crt) > len(ans) {
				ans = make([]int, len(crt))
				copy(ans, crt) // Copying the contents of `crt` to `ans`.
			}
		}
	}

	// Reversing `ans` to get the correct order of elements in the cycle.
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	// Printing the length of `ans` and the elements of `ans`.
	fmt.Println(len(ans))
	fmt.Println(strings.Join(intSliceToStringSlice(ans), " "))
}

// Helper function to convert a slice of integers to a slice of strings.
func intSliceToStringSlice(ints []int) []string {
	strs := make([]string, len(ints))
	for i, v := range ints {
		strs[i] = fmt.Sprintf("%d", v)
	}
	return strs
}
