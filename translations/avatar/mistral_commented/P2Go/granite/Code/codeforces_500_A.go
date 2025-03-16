
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initializing the scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Taking input for number of test cases and time limit
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	t, _ := strconv.Atoi(parts[1])

	// Initializing an empty slice to store the jumps
	s := make([]int, n)

	// Taking input for the jumps
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Split(line, " ")
	for i := 0; i < n; i++ {
		s[i], _ = strconv.Atoi(parts[i])
	}

	// Initializing the current cell position to 0
	currentCell := 0

	// Main logic of the program starts here
	for currentCell <= t {
		// Incrementing the current cell position by the jump from the previous cell
		currentCell += s[currentCell-1]

		// Checking if the current cell position is equal to the target position
		if currentCell == t {
			// If yes, then print "YES" and exit the program
			fmt.Println("YES")
			os.Exit(0)
		}

		// If not, then continue to the next iteration
		else {
			continue
		}
	}

	// If the loop terminates without finding the target position, then print "NO"
	fmt.Println("NO")
}

