
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read two integers from stdin
	a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize sum to 0
	sum := 0

	// Loop runs twice, each time adding the larger of the two numbers to sum
	// and decrementing that number by 1
	for i := 0; i < 2; i++ {
		if a >= b {
			sum += a
			a -= 1
		} else {
			sum += b
			b -= 1
		}
	}

	// Print the final sum to stdout
	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

