
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and m from input, representing the number of strings and some other parameter
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Create a set comprehension to calculate the difference in indices of 'S' and 'G' for each string
	// The difference is calculated as the index of 'S' minus the index of 'G'
	c := make(map[int]bool)
	for i := 0; i < n; i++ {
		s := readLine(reader)
		sS := strings.Index(s, "S")
		sG := strings.Index(s, "G")
		c[sS-sG] = true
	}

	// Check if any of the calculated differences are negative
	// If any difference is negative, print -1; otherwise, print the number of unique differences
	if anyNegative(c) {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func anyNegative(c map[int]bool) bool {
	for k := range c {
		if k < 0 {
			return true
		}
	}
	return false
}

