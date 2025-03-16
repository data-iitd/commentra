
package main

import (
	"fmt"
	"strings"
)

func main() {
	// read string a from standard input
	fmt.Scan(&a)
	n := len(a) // get the length of string a

	// read string b from standard input
	fmt.Scan(&b)
	m := len(b) // get the length of string b

	// iterate through all possible substrings of string a that have the same length as string b
	for i := 0; i+m <= n; i++ {
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		sum := 0

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for j := 0; j < m; j++ {
			// if the characters are different, increment sum by 1
			if a[i+j] != b[j] {
				sum++
			}
		}

		// update the minimum number of differences if a smaller number is found
		ans = min(ans, sum)
	}

	// print the minimum number of differences to standard output
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

