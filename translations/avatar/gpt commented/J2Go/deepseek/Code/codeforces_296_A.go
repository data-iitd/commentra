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
	defer writer.Flush()

	// Read the number of elements
	line, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(line))

	// Initialize an array to count occurrences of each index (up to 1000)
	array := make([]int, 1001)

	// Read n integers and count their occurrences
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		index, _ := strconv.Atoi(strings.TrimSpace(line))
		array[index]++
	}

	// Determine the maximum count of any index
	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}

	// Check if the maximum count is within allowed limits based on n being even or odd
	if n%2 == 0 {
		// For even n, check if the maximum count is less than or equal to n/2
		if countMax <= n/2 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	} else {
		// For odd n, check if the maximum count is less than or equal to n/2 + 1
		if countMax <= n/2+1 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}
