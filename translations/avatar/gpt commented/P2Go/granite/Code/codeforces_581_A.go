
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input and unpack them into variables a and b
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(readerReadLine(reader))
	b, _ := strconv.Atoi(readerReadLine(reader))

	// Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
	// Print the minimum value and the calculated half difference
	fmt.Printf("%d %d\n", min(a, b), (max(a, b)-min(a, b))/2)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

