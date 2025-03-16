
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the number of elements
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	// Initialize an array to count occurrences of each value shifted by 10
	cnt := make([]int, 21)
	// Count the occurrences of each value shifted by 10
	for i := 0; i < n; i++ {
		cnt[scan(reader) + 10]++
	}
	// Initialize result variable
	res := 0
	// Calculate the number of pairs that sum up to 20
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i]
	}
	// Special case for pairs where both elements are the same (i.e., i = 10)
	res += (cnt[10] * (cnt[10] - 1)) / 2
	// Output the result
	fmt.Println(res)
}

// scan reads a single line from stdin
func scan(reader *bufio.Reader) int {
	// Read a single line
	line, _ := reader.ReadString('\n')
	// Return the integer value of the line
	return atoi(line)
}

// atoi converts a string to an integer
func atoi(s string) int {
	i, _ := strconv.Atoi(strings.TrimSpace(s))
	return i
}

