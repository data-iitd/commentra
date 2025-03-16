

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read input integers a, b, c, and d
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	tokens := strings.Split(input, " ")
	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])
	c, _ := strconv.Atoi(tokens[2])
	d, _ := strconv.Atoi(tokens[3])

	// Check if c is greater than b
	if c > b {
		// If yes, print 0 and exit
		fmt.Fprintln(writer, 0)
		writer.Flush()
		return
	}

	// Check if a is greater than d
	else if a > d {
		// If yes, print 0 and exit
		fmt.Fprintln(writer, 0)
		writer.Flush()
		return
	}

	// Check if a is less than c
	else if a < c {
		// If yes, calculate the difference between the smaller and larger of b and d
		difference := int(math.Min(float64(b), float64(d))) - c
		// Print the difference
		fmt.Fprintln(writer, difference)
		writer.Flush()
		return
	}

	// If none of the above conditions are true, then a, b, c, and d are in sorted order
	else {
		// Create a List of integers a, b, c, and d
		l := []int{a, b, c, d}

		// Sort the List in ascending order
		sort.Ints(l)

		// Calculate the difference between the second and third elements of the List
		difference := l[2] - l[1]

		// Print the difference
		fmt.Fprintln(writer, difference)
		writer.Flush()
	}
}

