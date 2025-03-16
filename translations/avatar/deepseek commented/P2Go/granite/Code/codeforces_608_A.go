
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of events (n) and the starting time (s)
	n, s := readTwoInt()

	// Initialize the maximum additional time to 0
	c := 0

	// Loop through each event
	for i := 0; i < n; i++ {
		// Read the finish time (f) and the time taken (t) for the current event
		f, t := readTwoInt()

		// Calculate the additional time required if the event starts at time s
		x := t - (s - f)

		// Update the maximum additional time if the current event requires more time
		if x > c {
			c = x
		}
	}

	// Print the total time including the maximum additional time
	fmt.Println(s + c)
}

func readTwoInt() (int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	return x, y
}

