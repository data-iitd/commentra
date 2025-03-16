package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Initialize buffered reader for input
	writer := bufio.NewWriter(os.Stdout) // Initialize buffered writer for output
	defer writer.Flush()                  // Ensure the writer is flushed at the end

	var n, k int
	fmt.Fscan(reader, &n, &k) // Read the number of logs and the number of days

	// Read the lengths of the logs
	logsLength := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &logsLength[i])
	}

	// Initialize the minimum and maximum possible days
	min, max := 1, int(1e9)+1000

	// Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
	for min < max {
		mid := (min + max) / 2 // Calculate the middle day
		if nei(mid, logsLength, k) { // If the number of days needed to cut the logs is greater than or equal to k
			max = mid // Narrow down the search space to the left
		} else {
			min = mid + 1 // Narrow down the search space to the right
		}
	}

	// Print the minimum day as the output
	fmt.Fprintln(writer, min)
}

// Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
func nei(mid int, logsLength []int, k int) bool {
	daysNeeded := 0 // Initialize the days needed to zero

	// Iterate through all the logs and calculate the days needed to cut them
	for _, log := range logsLength {
		daysNeeded += (log + mid - 1) / mid // Calculate the days needed to cut the current log
		k -= daysNeeded // Subtract the days needed from the remaining days
		if k < 0 { // If the remaining days are not sufficient to cut all the logs
			return false // Return false to indicate that the middle day is not the answer
		}
	}

	// If all the logs have been cut, return true to indicate that the middle day is the answer
	return true
}
