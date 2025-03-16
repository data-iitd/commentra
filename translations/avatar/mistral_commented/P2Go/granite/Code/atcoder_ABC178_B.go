
###
# Code
###

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read an integer list from standard input
func LI( ) []int {
	s := make([]int, 0)
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		text := scanner.Text()
		a, _ := fmt.Sscanf(text, "%d", &a)
		s = append(s, a...)
	}
	return s
}

// Function to read an integer from standard input
func I( ) int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	a, _ := fmt.Sscanf(text, "%d", &a)
	return a
}

// Function to read a float from standard input
func F( ) float64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	a, _ := fmt.Sscanf(text, "%f", &a)
	return a
}

// Function to read a list from standard input, split by space
func LS( ) []string {
	s := make([]string, 0)
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		text := scanner.Text()
		a, _ := fmt.Sscanf(text, "%s", &a)
		s = append(s, a...)
	}
	return s
}

// Function to read a string from standard input
func S( ) string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()
	return text
}

// Main function
func main( ) {
	// Read input values
	a := I()
	b := I()
	c := I()
	d := I()

	// Calculate the maximum product of pairs of numbers
	result := max(a*c, b*d, a*d, b*c)

	// Print the result
	fmt.Println(result)
}

// Function to calculate the maximum value
func max(a, b, c, d int) int {
	m := a
	if m < b {
		m = b
	}
	if m < c {
		m = c
	}
	if m < d {
		m = d
	}
	return m
}

// Call the main function
func main( ) {
	main()
}
