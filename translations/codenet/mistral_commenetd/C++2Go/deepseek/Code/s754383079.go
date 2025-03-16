package main

import (
	"fmt"
	"strings"
)

const M = 1010 // maximum size of strings a and b

var a, b string // strings a and b
var n, m, ans int // n is the length of string a, m is the length of string b, ans is the minimum number of differences between strings a and b

func main() {
	// read string a from standard input
	fmt.Scan(&a)
	n = len(a) // get the length of string a

	// read string b from standard input
	fmt.Scan(&b)
	m = len(b) // get the length of string b

	// iterate through all possible substrings of string a that have the same length as string b
	for i := 1; i+m-1 <= n; i++ {
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		sum := 0

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for j := 1; j <= m; j++ {
			// if the characters are different, increment sum by 1
			if a[i+j-1] != b[j-1] {
				sum++
			}
		}

		// update the minimum number of differences if a smaller number is found
		if sum < ans {
			ans = sum
		}
	}

	// print the minimum number of differences to standard output
	fmt.Println(ans)
}

