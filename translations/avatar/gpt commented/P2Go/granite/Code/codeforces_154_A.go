
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the main string from user input
	s := readString()

	// Read the number of subsequent strings to process
	n := readInt()

	// Initialize the answer variable to accumulate results
	ans := 0

	// Loop through each of the n strings provided by the user
	for i := 0; i < n; i++ {
		// Read the current string
		x := readString()

		// Initialize counters for characters matching the first and second characters of x
		a, b := 0, 0

		// Loop through each character in the main string s
		for j := 0; j < len(s); j++ {
			// If the character matches the first character of x, increment counter a
			if string(s[j]) == string(x[0]) {
				a++
			}
			// If the character matches the second character of x, increment counter b
			else if string(s[j]) == string(x[1]) {
				b++
			} else {
				// If a character does not match either, add the minimum of a and b to ans
				ans = ans + min(a, b)
				// Reset counters a and b for the next segment
				a, b = 0, 0
			}
		}

		// After finishing the loop, add the minimum of a and b to ans for the last segment
		ans = ans + min(a, b)
	}

	// Print the final accumulated answer
	fmt.Println(ans)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

