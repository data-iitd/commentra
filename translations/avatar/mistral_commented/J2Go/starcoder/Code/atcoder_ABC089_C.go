
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve(n int, in *bufio.Reader, out *bufio.Writer) {
	// Initialize an array of size 5 to store counts
	cnt := make([]int, 5)
	for i := 0; i < 5; i++ {
		cnt[i] = 0
	}

	// Read the number of test cases
	for i := 0; i < n; i++ {
		// Read a string from input
		str, _ := in.ReadString('\n')
		str = strings.TrimSpace(str)

		if str[0] == 'M' {
			// If the first character of the string is 'M', increment the count of 'M'
			cnt[0]++
		} else if str[0] == 'A' {
			// If the first character of the string is 'A', increment the count of 'A'
			cnt[1]++
		} else if str[0] == 'R' {
			// If the first character of the string is 'R', increment the count of 'R'
			cnt[2]++
		} else if str[0] == 'C' {
			// If the first character of the string is 'C', increment the count of 'C'
			cnt[3]++
		} else if str[0] == 'H' {
			// If the first character of the string is 'H', increment the count of 'H'
			cnt[4]++
		}
	}

	// Calculate the first product
	res := cnt[0] * cnt[1] * cnt[2] +
		// Calculate the second product
		cnt[0] * cnt[1] * cnt[3] +
		// Calculate the third product
		cnt[0] * cnt[1] * cnt[4] +
		// Calculate the fourth product
		cnt[0] * cnt[2] * cnt[3] +
		// Calculate the fifth product
		cnt[0] * cnt[2] * cnt[4] +
		// Calculate the sixth product
		cnt[0] * cnt[3] * cnt[4] +
		// Calculate the seventh product
		cnt[1] * cnt[2] * cnt[3] +
		// Calculate the eighth product
		cnt[1] * cnt[2] * cnt[4] +
		// Calculate the ninth product
		cnt[1] * cnt[3] * cnt[4] +
		// Calculate the tenth product
		cnt[2] * cnt[3] * cnt[4]

	// Write the result to the output
	out.WriteString(strconv.FormatInt(res, 10) + "\n")
}

func main() {
	// Read input from stdin
	in := bufio.NewReader(os.Stdin)
	// Write output to stdout
	out := bufio.NewWriter(os.Stdout)

	// Read the number of test cases
	n, _ := strconv.Atoi(in.ReadString('\n'))

	solve(n, in, out)

	// Close the output writer
	out.Flush()
}

