
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers from the user, separated by a space
	A, _ := strconv.Atoi(readerReadLine(reader))
	B, _ := strconv.Atoi(readerReadLine(reader))

	// Calculate the difference between A and 2 times B
	ans := A - 2 * B

	// Check if the difference is negative
	if ans < 0 {
		// If it is, set it to zero
		ans = 0
	}

	// Print the final answer
	fmt.Println(ans)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

