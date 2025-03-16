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
	// Read first line of input
	line, _ := reader.ReadString('\n')
	// Convert the string to a number
	A, _ := strconv.Atoi(strings.TrimSpace(line))
	// Read second line of input
	line, _ = reader.ReadString('\n')
	// Convert the string to a number
	B, _ := strconv.Atoi(strings.TrimSpace(line))
	// Initialize variables for storing remainders and result
	amari := 0
	result := 0
	// Calculate the result by dividing B by A - 1 and storing the quotient
	result = (B - 1) / (A - 1)
	// Calculate the remainder of B divided by A - 1 and store it in amari
	amari = (B - 1) % (A - 1)
	// Check if the remainder is not zero
	if amari!= 0 {
		// If the remainder is not zero, increment the result by 1
		result += 1
	}
	// Write the result to stdout
	fmt.Println(result)
}

