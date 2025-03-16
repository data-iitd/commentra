
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers `n` and `m` from the standard input, separated by a space
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(line))
	line, _ = reader.ReadString('\n')
	m, _ := strconv.Atoi(strings.TrimSpace(line))

	// Initialize a variable `i` to 1
	i := 1

	// The while loop starts
	for m >= i {
		// Subtract `i` from `m`
		m -= i

		// Update the value of `i` by calculating `(i % n) + 1`
		i = (i % n) + 1
	}

	// Once the loop finishes, print the final value of `m` to the standard output
	fmt.Println(m)
}

