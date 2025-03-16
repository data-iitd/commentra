package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Taking input for number of test cases and time limit
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	t, _ := strconv.Atoi(parts[1])

	// Initializing an empty list to store the jumps
	sInput, _ := reader.ReadString('\n')
	sParts := strings.Split(strings.TrimSpace(sInput), " ")
	s := make([]int, len(sParts))
	for i, v := range sParts {
		s[i], _ = strconv.Atoi(v)
	}

	// Initializing the current cell position to 0
	currentCell := 0

	// Main logic of the program starts here
	for currentCell < t {
		// Incrementing the current cell position by the jump from the previous cell
		currentCell += s[currentCell] - 1

		// Checking if the current cell position is equal to the target position
		if currentCell == t-1 {
			// If yes, then print "YES" and exit the program
			fmt.Println("YES")
			return
		}

		// If not, then continue to the next iteration
		continue
	}

	// If the loop terminates without finding the target position, then print "NO"
	fmt.Println("NO")
}
