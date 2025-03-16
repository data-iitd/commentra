
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)

	// Read the number of intervals (n) and the starting point (s)
	n, _ := strconv.Atoi(read(reader))
	s, _ := strconv.Atoi(read(reader))

	// Initialize a variable to keep track of the maximum additional distance (c)
	c := 0

	// Iterate over each interval
	for i := 0; i < n; i++ {
		// Read the start (f) and end (t) of the interval
		f, _ := strconv.Atoi(read(reader))
		t, _ := strconv.Atoi(read(reader))

		// Calculate the additional distance that can be covered
		x := t - (s - f)

		// Update the maximum additional distance if the current one is greater
		if x > c {
			c = x
		}
	}

	// Output the total distance covered, which is the starting point plus the maximum additional distance
	fmt.Println(s + c)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

