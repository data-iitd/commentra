
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of pairs
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize list `l` with zeros
	l := make([]int, 1000010)

	// Read `n` pairs of integers and store them in list `l`
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		l[a] = b
	}

	// Initialize list `dp` with zeros
	dp := make([]int, 1000010)

	// If the value at index 0 in `l` is greater than 0, set `dp[0]` to 1
	if l[0] > 0 {
		dp[0] = 1
	}

	mx := 0  // Initialize variable `mx` to 0

	// Iterate through the list `l` from 1 to 1000010, updating the `dp` list
	for i := 1; i < 1000010; i++ {
		if l[i] == 0 {  // If `l[i]` is 0, copy the value from `dp[i-1]`
			dp[i] = dp[i-1]
		} else {
			if l[i] >= i {  // If `l[i]` is greater than or equal to `i`, set `dp[i]` to 1
				dp[i] = 1
			} else {  // Otherwise, update `dp[i]` based on the previous value
				dp[i] = dp[i-l[i]-1] + 1
			}
		}
		if dp[i] > mx {  // Update `mx` if `dp[i]` is greater than the current `mx`
			mx = dp[i]
	}

	// Print the result as `n - mx`
	fmt.Println(n - mx)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

