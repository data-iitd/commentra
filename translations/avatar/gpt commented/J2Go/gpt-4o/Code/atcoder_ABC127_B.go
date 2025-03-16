package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input
	scanner.Scan()
	line := scanner.Text()
	tokens := strings.Fields(line)

	// Parse integer values for r and d, and a long value for x from the input
	r, _ := strconv.Atoi(tokens[0])
	d, _ := strconv.Atoi(tokens[1])
	x, _ := strconv.ParseInt(tokens[2], 10, 64)

	// Perform the calculation and output the result 10 times
	for i := 0; i < 10; i++ {
		// Update x according to the formula x = r * x - d
		x = int64(r)*x - int64(d)
		// Print the updated value of x
		fmt.Println(x)
	}
}

// <END-OF-CODE>
