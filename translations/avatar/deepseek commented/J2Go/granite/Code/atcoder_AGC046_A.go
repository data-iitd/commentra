

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)
	// Create a variable to store the input
	var x int
	// Read an integer input
	sc.Scan()
	x, _ = strconv.Atoi(sc.Text())
	// Initialize a counter to keep track of the number of iterations
	count := 0
	// Store the initial value of x in a temporary variable
	tmp := x
	// Initialize x to 0 to start the loop
	x = 0
	// Loop until x becomes 360
	for x!= 360 {
		// Increment x by tmp
		x = x + tmp
		// If x exceeds 360, adjust it by subtracting 360
		if x > 360 {
			x = x - 360
		}
		// Increment the counter
		count++
	}
	// Print the final count
	fmt.Println(count)
}

