package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input
	scanner.Scan()
	// Split the input into a slice of strings
	input := strings.Split(scanner.Text(), " ")
	// Convert the first two elements of the slice to integers
	r, _ := strconv.Atoi(input[0])
	d, _ := strconv.Atoi(input[1])

	// Read the next line of input
	scanner.Scan()
	// Convert the input to an integer
	x, _ := strconv.Atoi(scanner.Text())

	// Perform the calculation 10 times
	for i := 0; i < 10; i++ {
		// Update x according to the formula x = r * x - d
		x = r * x - d
		// Print the updated value of x
		fmt.Println(x)
	}
}

