package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input efficiently
	sc := bufio.NewScanner(os.Stdin)
	// Create a writer to output results
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read an integer input from the user
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	// Initialize a counter to keep track of the number of rotations
	count := 0
	// Store the original value of x for later use
	tmp := x
	// Reset x to 0 for the rotation calculation
	x = 0

	// Loop until x completes a full rotation (360 degrees)
	for x != 360 {
		// Increment x by the original input value
		x += tmp
		// If x exceeds 360, wrap it around by subtracting 360
		if x > 360 {
			x -= 360
		}
		// Increment the count of rotations
		count++
	}

	// Output the total number of rotations needed to reach 360 degrees
	fmt.Println(count)
}
