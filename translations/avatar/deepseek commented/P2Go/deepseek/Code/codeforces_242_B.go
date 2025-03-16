package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))
	
	// Initialize variables to track the best candidate interval
	id := 0
	l, r := readPair(reader)
	
	// Process each interval
	for i := 1; i < n; i++ {
		li, ri := readPair(reader)
		// Check if the current interval completely covers the best candidate interval
		if li <= l && r <= ri {
			id = i
		}
		// Check if the current interval overlaps with the best candidate interval
		else if li < l || r < ri {
			id = n
		}
		// Update the boundaries of the best candidate interval
		if li < l {
			l = li
		}
		if ri > r {
			r = ri
		}
	}
	
	// Output the result
	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readPair(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	li, _ := strconv.Atoi(parts[0])
	ri, _ := strconv.Atoi(parts[1])
	return li, ri
}
