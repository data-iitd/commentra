
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers from input and assign them to x and y
	x, _ := strconv.Atoi(read(reader))
	y, _ := strconv.Atoi(read(reader))

	// Calculate the maximum value based on the formula and print it
	// The formula computes x + y - 3 and adjusts based on the difference between y and x
	// It ensures the result is not negative by taking the maximum with 0
	fmt.Println(max(x+y-3+(y-x)%3>0, 0))
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

