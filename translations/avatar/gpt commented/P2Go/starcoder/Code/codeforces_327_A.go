package main

import (
	"fmt"
	"strings"
)

func find(s string, ch byte) []int {
	// This function returns a list of indices where the character 'ch' appears in the string's'.
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	// Read an integer input 'n' which represents the length of the string.
	var n int
	fmt.Scanf("%d", &n)

	// Read the string input's' and replace any empty string occurrences (this line seems to be incorrect).
	s := strings.Replace(input(), "", "", -1)

	// Check if the string's' contains the character '0'.
	if strings.IndexByte(s, '0') == -1 {
		// If '0' is not present, the output is n - 1.
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string's'.
		indices := find(s, '0')

		// If there is only one '0', output the length of the string 'n'.
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize a variable to keep track of the maximum value found.
			var maximum int

			// Generate all combinations of indices of '0' taken 2 at a time.
			combs := combinations(indices, 2)

			// Iterate through each combination of indices.
			for x := range combs {
				// Calculate the maximum value based on the distance between the two indices.
				maximum = max(maximum, 2 + 2*(abs(indices[x[0]]-indices[x[1]])-1)-(abs(x[0]-x[1])-1))
			}

			// Output the count of '1's in the string plus the maximum value calculated.
			fmt.Println(strings.Count(s, "1") + maximum)
	}
}

func combinations(arr []int, r int) [][]int {
	// This function generates all combinations of indices of '0' taken 'r' at a time.
	var combs [][]int
	n := len(arr)
	indices := make([]int, r)
	for i := 0; i < r; i++ {
		indices[i] = i
	}
	count := 0
	for {
		var comb []int
		for _, i := range indices {
			comb = append(comb, arr[i])
		}
		combs = append(combs, comb)
		count++
		i := r - 1
		for ; i >= 0; i-- {
			if indices[i]!= n-r+i {
				break
			}
		}
		if i < 0 {
			break
		}
		indices[i]++
		for j := i + 1; j < r; j++ {
			indices[j] = indices[j-1] + 1
		}
	}
	return combs
}

func max(a, b int) int {
	// This function returns the maximum value between 'a' and 'b'.
	if a > b {
		return a
	}
	return b
}

func input() string {
	// This function reads a string input from stdin.
	var s string
	fmt.Scanf("%s", &s)
	return s
}

