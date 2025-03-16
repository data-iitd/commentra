
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())

	// Initialize variables to track the best candidate interval
	id := 0
	l, r := 0, 0

	// Process each interval
	for i := 0; i < n; i++ {
		li, ri := readInterval()
		// Check if the current interval completely covers the best candidate interval
		if li <= l && r <= ri {
			id = i
		}
		// Check if the current interval overlaps with the best candidate interval
		if li < l || r < ri {
			id = n
		}
		// Update the boundaries of the best candidate interval
		l = min(l, li)
		r = max(r, ri)
	}

	// Output the result
	fmt.Println(-1, id+1)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _ := buf.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInterval() (int, int) {
	line := readLine()
	li, ri := strings.Split(line, " "), strings.Split(line, " ")
	return parseInt(li[0]), parseInt(ri[1])
}

func parseInt(str string) int {
	i, _ := strconv.Atoi(str)
	return i
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

