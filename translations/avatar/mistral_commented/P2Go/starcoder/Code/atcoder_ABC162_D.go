package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Convert the string to an integer
	n, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}

	// Read the second line of input from stdin
	line, err = reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Convert the string to a slice of runes
	s := []rune(strings.TrimSpace(line))

	// Call the calculate function with the input values n and s
	calculate(n, s)
}

// Define a function calculate that takes two arguments: an integer n and a slice of runes s
func calculate(n int, s []rune) {
	// Initialize a variable sum to 0
	sum := 0

	// Use a for loop to iterate through each step from 1 to the ceiling of n/2
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Initialize a variable i to 0
		i := 0

		// Initialize a variable s to the empty string
		s := ""

		// Use a for loop to iterate through each of the next three elements of the slice s
		for _ := 0; _ < 3; _++ {
			// Append the next element of the slice s to the string s
			s += string(s[i])
			i++
		}

		// Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
		if s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB" {
			sum += 1
	}

	// Print the result of the calculation: rNum * gNum * bNum - sum
	fmt.Println(rNum * gNum * bNum - sum)
}

