package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read three integers from input: t (target), s (initial value), and q (growth factor)
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	t, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	s, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	q, _ := strconv.Atoi(line)

	// Initialize a counter for the number of iterations
	ans := 0

	// Loop until the initial value s is less than the target t
	for s < t {
		// Multiply the current value of s by the growth factor q
		s *= q
		// Increment the counter for each multiplication
		ans += 1
	}

	// Print the total number of multiplications needed for s to reach or exceed t
	fmt.Println(ans)
}

