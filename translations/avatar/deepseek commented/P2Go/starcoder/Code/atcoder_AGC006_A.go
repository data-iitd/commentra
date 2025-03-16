
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the integer input `n`
	n, _ := strconv.Atoi(readLine())
	// Read the list `s` of length `n`
	s := strings.Split(readLine(), " ")
	// Read the list `t` of length `n`
	t := strings.Split(readLine(), " ")

	// Check if the lists `s` and `t` are equal
	if s == t {
		// If they are equal, print `n`
		fmt.Println(n)
	} else {
		cnt := 0  // Initialize the counter `cnt` to 0
		// Compare elements of `s` and `t` starting from each index `i` of `s`
		for i := 0; i < n; i++ {
			for j := 0; j < n-i; j++ {
				// If a mismatch is found, break out of the inner loop
				if s[i+j]!= t[j] {
					break
				}
				// If the end of the inner list is reached without breaking, set `cnt`
				if j == n-i-1 {
					cnt = n - i
			}
		}
		// Print `2 * n - cnt`
		fmt.Println(2*n - cnt)
	}
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _ := buf.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

