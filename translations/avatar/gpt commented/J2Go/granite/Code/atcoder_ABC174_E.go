
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of logs and the value of k
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	k, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Read the lengths of the logs into an array
	logsLength := make([]int, n)
	for i := 0; i < n; i++ {
		logsLength[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}

	// Initialize binary search bounds
	min, max := 1, 1e9+1000

	// Perform binary search to find the minimum possible length
	for min < max {
		mid := (min + max) / 2

		// Check if it's possible to cut the logs with the current mid length
		if nei(mid, logsLength, k) {
			max = mid
		} else {
			min = mid + 1
		}
	}

	// Output the minimum length found
	fmt.Fprintf(writer, "%d\n", min)
	writer.Flush()
}

func nei(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
}

// Translate the above Java code to Go and end with comment "