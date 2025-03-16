package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line from standard input and remove trailing whitespace
func S() string {
	r := bufio.NewReader(os.Stdin)
	s, _ := r.ReadString('\n')
	return strings.TrimSpace(s)
}

// Function to read an integer from standard input
func I() int {
	i, _ := strconv.Atoi(S())
	return i
}

// Function to read a list of integers from standard input
func LI() []int {
	line := strings.Split(S(), " ")
	var li []int
	for _, s := range line {
		i, _ := strconv.Atoi(s)
		li = append(li, i)
	}
	return li
}

// Function to read a list of strings from standard input
func LS() []string {
	return strings.Split(S(), " ")
}

func main() {
	// Read two integers from input
	a, b := LI()

	// Check if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output 'Positive' if 'a' is greater than 0
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero") // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
	} else {
		// If 'a' is negative and 'b' is also negative
		if (a + b) % 2 == 0 {
			fmt.Println("Negative") // Output 'Negative' if the sum of 'a' and 'b' is even
		} else {
			fmt.Println("Positive") // Output 'Positive' if the sum of 'a' and 'b' is odd
	}
}

