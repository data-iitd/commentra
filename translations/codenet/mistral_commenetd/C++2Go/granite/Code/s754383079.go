

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// read string a from standard input
	a, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	a = strings.TrimSpace(a)
	n := len(a) // get the length of string a

	// read string b from standard input
	b, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	b = strings.TrimSpace(b)
	m := len(b) // get the length of string b

	// initialize ans to the maximum possible value
	ans := n + 10

	// iterate through all possible substrings of string a that have the same length as string b
	for i := 0; i <= n-m; i++ {
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		sum := 0

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for j := 0; j < m; j++ {
			// if the characters are different, increment sum by 1
			if a[i+j]!= b[j] {
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

