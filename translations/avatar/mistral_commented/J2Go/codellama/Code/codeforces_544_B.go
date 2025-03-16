package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize a Scanner object to read input from the standard input stream
	scan := bufio.NewScanner(os.Stdin)
	// Read the first integer 'n' from the input
	n, _ := strconv.Atoi(scan.Text())
	// Read the second integer 'count' from the input
	count, _ := strconv.Atoi(scan.Text())
	// Call the printIsland method with the arguments 'n' and 'count'
	printIsland(n, count)
}

// Method to check if it's possible to place the required number of 'L' islands in the grid
func printIsland(n, count int) {
	// Calculate the side length 'a' of the square grid of size 'n x n'
	a := (n + 1) / 2
	// Calculate the square of the side length 'b' of the grid
	b := n / 2
	// Calculate the maximum number of 'L' islands that can be placed in the grid
	max := a*a + b*b

	// Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
	if count > max {
		fmt.Println("NO") // If yes, print "NO" and return from the method
		return
	}

	fmt.Println("YES") // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

	// Initialize a StringBuilder object 'sb' to store a row of the grid
	for i := 0; i < n; i++ {
		sb := strings.Builder{}
		for j := 0; j < n; j++ {
			// If the cell is in the position where an 'L' island can be placed, append an 'L' character to the StringBuilder object and decrement the count
			if (i+j)%2 == 0 && count > 0 {
				sb.WriteString("L")
				count--
			} else {
				// Otherwise, append an 'S' character to the StringBuilder object
				sb.WriteString("S")
			}
		}
		// Print the contents of the StringBuilder object to represent a row of the grid
		fmt.Println(sb.String())
	}
}

