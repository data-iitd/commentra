package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read an integer from input
	k := readInt(reader)

	// Initialize a variable to hold the current value of t
	t := 0

	// Loop through numbers from 1 to k
	for i := 1; i <= k; i++ {
		// Update t by appending a '7' at the end and taking modulo k
		t = t % k * 10 + 7

		// Check if the current value of t is divisible by k
		if t % k == 0 {
			fmt.Fprintln(writer, i) // Print the current index if divisible
			return
		}
	}

	// If no index was found, print -1
	fmt.Fprintln(writer, -1)
}

// Helper function to read an integer from input
func readInt(reader *bufio.Reader) int {
	numStr, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(numStr[:len(numStr)-1])
	return num
}
