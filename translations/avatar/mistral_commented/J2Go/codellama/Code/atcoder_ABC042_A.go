package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a new scanner to read input from console
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input from the console
	scanner.Scan()

	// Split the line into an array of strings using space character as delimiter
	list := strings.Split(scanner.Text(), " ")

	// Parse the first three elements of the array as integers x, a, and y
	x, _ := strconv.Atoi(list[0])
	a, _ := strconv.Atoi(list[1])
	y, _ := strconv.Atoi(list[2])

	// Initialize a string variable h with the value "NO"
	h := "NO"

	// Check if any of the numbers x, a, or y are equal to 5 or 7
	if x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7 {
		// If any of the numbers satisfy the condition, check if their sum is equal to 17
		if x+y+a == 17 {
			// If the sum is equal to 17, set the value of h to "YES"
			h = "YES"
		}
	}

	// Print the value of h to the console
	fmt.Println(h)
}

