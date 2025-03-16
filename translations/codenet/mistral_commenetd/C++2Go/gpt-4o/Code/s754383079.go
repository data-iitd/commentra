package main

import (
	"fmt"
	"strings"
)

const M = 1010 // maximum size of strings a and b

func main() {
	var a, b [M]rune // strings a and b
	var n, m, ans int = M + 10, M + 10, M + 10 // n is the length of string a, m is the length of string b, ans is the minimum number of differences

	// read string a from standard input
	fmt.Scanf("%s", &a[1])
	n = len(strings.TrimSpace(string(a[1:]))) // get the length of string a

	// read string b from standard input
	fmt.Scanf("%s", &b[1])
	m = len(strings.TrimSpace(string(b[1:]))) // get the length of string b

	// iterate through all possible substrings of string a that have the same length as string b
	for i := 1; i+m-1 <= n; i++ {
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		sum := 0

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for j := 1; j <= m; j++ {
			// if the characters are different, increment sum by 1
			if a[i+j-1] != b[j] {
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

	// terminate the program with exit code 0
}
