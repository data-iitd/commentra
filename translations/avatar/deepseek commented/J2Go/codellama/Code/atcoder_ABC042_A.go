
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input from the user
	scanner.Scan()
	line := scanner.Text()

	// Split the input line into an array of strings
	list := strings.Split(line, " ")

	// Parse the first three elements of the array as integers
	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])

	// Initialize a variable to store the result
	h := "NO"

	// Check if any of the integers is either 5 or 7
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		// Check if the sum of the integers is 17
		if x+y+a == 17 {
			h = "YES"
		}
	}

	// Print the result
	fmt.Println(h)
}

