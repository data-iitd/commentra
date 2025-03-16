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

	// Read the number of elements `n` and the number of queries `k` from the standard input
	line1, _ := reader.ReadString('\n')
	line1 = strings.TrimSpace(line1)
	parts1 := strings.Split(line1, " ")
	n, _ := strconv.Atoi(parts1[0])
	k, _ := strconv.Atoi(parts1[1])

	// Read a single string `v` from the standard input
	line2, _ := reader.ReadString('\n')
	line2 = strings.TrimSpace(line2)
	v := line2

	// Initialize a list `d` with two elements: "LEFT" and "RIGHT"
	d := []string{"LEFT", "RIGHT"}

	// Determine the direction based on the difference between `k` and `n-k`
	f := k-1 < n-k

	// Determine the number of elements to be appended to the list `a`
	m := min(k-1, n-k)

	// Initialize an empty list `a`
	a := []string{}

	// Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
	for i := 0; i < m; i++ {
		a = append(a, d[1-f])
	}

	// Iterate through the string `v` with a step of 2 times the value of `f`
	for i := 0; i < len(v); i += 2 * f {
		// Append "PRINT <character>" and the corresponding direction to the list `a`
		a = append(a, fmt.Sprintf("PRINT %c", v[i]))
		a = append(a, d[f])
	}

	// Print all the elements of the list `a`, except the last one, separated by newline characters
	for i := 0; i < len(a)-1; i++ {
		fmt.Println(a[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
