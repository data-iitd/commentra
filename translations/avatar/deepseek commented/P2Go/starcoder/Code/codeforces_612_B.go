
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input representing the length of the list `a`
	n, _ := strconv.Atoi(readLine())

	// Take a space-separated string of integers and convert them to a list `a` of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.Split(readLine(), " ")[i])
	}

	// Initialize an empty list `b` of length `n`
	b := make([]int, n)

	// Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}

	res := 0  // Initialize the result variable `res` to 0

	// Calculate the sum of absolute differences between the positions of consecutive elements in `b`
	for i := 1; i < n; i++ {
		res += abs(b[i] - b[i-1])
	}

	fmt.Println(res)  // Print the result
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _ := buf.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

