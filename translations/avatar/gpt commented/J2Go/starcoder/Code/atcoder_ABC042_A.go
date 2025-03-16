package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from stdin.
	line, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		return
	}

	// Split the line into a slice of strings.
	list := strings.Split(line, " ")

	// Convert the first three elements of the slice to integers.
	x, err := strconv.Atoi(list[0])
	if err!= nil {
		fmt.Println(err)
		return
	}
	a, err := strconv.Atoi(list[1])
	if err!= nil {
		fmt.Println(err)
		return
	}
	y, err := strconv.Atoi(list[2])
	if err!= nil {
		fmt.Println(err)
		return
	}

	// Initialize a variable to hold the result, defaulting to "NO".
	h := "NO"

	// Check if any of the numbers x, a, or y are either 5 or 7.
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		// If the sum of x, a, and y equals 17, set the result to "YES".
		if x+y+a == 17 {
			h = "YES"
		}
	}

	// Output the result.
	fmt.Println(h)
}

