package main // Package main is the entry point of the program

import (
	"bufio" // Importing bufio for efficient input reading
	"fmt"   // Importing fmt for formatted I/O
	"os"    // Importing os for standard input/output
	"strconv" // Importing strconv for string conversion
)

func main() { // Main function is the entry point of the program
	reader := bufio.NewReader(os.Stdin) // Create a new buffered reader for standard input
	writer := bufio.NewWriter(os.Stdout) // Create a new buffered writer for standard output
	defer writer.Flush() // Ensure the writer flushes the output buffer at the end

	var n, k int
	fmt.Fscan(reader, &n, &k) // Read the number of logs and the number of cuts allowed
	logsLength := make([]int, n) // Create a slice to hold the lengths of the logs
	for i := 0; i < n; i++ { // Read the lengths of the logs
		fmt.Fscan(reader, &logsLength[i])
	}

	min, max := 1, int(1e9)+1000 // Initialize the binary search range
	for min < max { // Perform binary search
		mid := (min + max) / 2 // Calculate the middle value
		if canCut(mid, logsLength, k) { // Check if the current mid can be used to cut all logs
			max = mid // Adjust the max value to search in the lower half
		} else {
			min = mid + 1 // Adjust the min value to search in the upper half
		}
	}
	fmt.Fprintln(writer, min) // Print the result
}

func canCut(mid int, logsLength []int, k int) bool { // canCut checks if the current mid can be used to cut all logs
	for _, log := range logsLength { // Iterate through each log
		k -= (log + mid - 1) / mid - 1 // Calculate the number of cuts needed for the current log
		if k < 0 { // If k is negative, it means we cannot make the required cuts
			return false // Return false as the current mid cannot be used
		}
	}
	return true // Return true if all logs can be cut with the given number of k
}
