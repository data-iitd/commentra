

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read in five integers from the standard input
	princess, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	dragon, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	t, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	f, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	c, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Check if the dragon is smaller than or equal to the princess
	// If so, print 0 and exit the program
	if dragon <= princess {
		fmt.Println(0)
		return
	}

	// Initialize a variable result to 0
	result := 0

	// Calculate an initial position based on t and princess
	position := t * princess

	// Enter a while loop that continues as long as the position is less than c
	for position < c {
		// Increment result by 1
		result += 1

		// Update the position by adding the given terms
		position += princess * position / dragon
		position += princess * f
		position += princess * position / (dragon - princess)
	}

	// Once the loop terminates, print the final value of result
	fmt.Println(result)
}

