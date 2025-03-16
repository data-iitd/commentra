
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to hold the input values
	var h1, h2, m1, m2, k int

	// Create a scanner to read input values from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read input values: start time (h1:m1), end time (h2:m2), and a duration k
	scanner.Scan()
	fields := strings.Split(scanner.Text(), " ")
	h1, _ = strconv.Atoi(fields[0])
	m1, _ = strconv.Atoi(fields[1])
	scanner.Scan()
	fields = strings.Split(scanner.Text(), " ")
	h2, _ = strconv.Atoi(fields[0])
	m2, _ = strconv.Atoi(fields[1])
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	// Calculate the total minutes from the start time to the end time
	ans := h2*60 + m2 - (h1*60 + m1)

	// Output the result after subtracting the duration k from the total minutes
	fmt.Println(ans - k)
}

