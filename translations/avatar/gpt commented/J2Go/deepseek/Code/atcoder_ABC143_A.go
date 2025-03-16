package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read a line of input, trim whitespace, and split it into an array of strings
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(strings.TrimSpace(line), " ")
	
	// Parse the first and second elements of the array as integers
	a, err := strconv.Atoi(parts[0])
	if err != nil {
		fmt.Println("Error parsing first number")
		return
	}
	b, err := strconv.Atoi(parts[1])
	if err != nil {
		fmt.Println("Error parsing second number")
		return
	}
	
	// Calculate the value of c based on the formula: c = a - b * 2
	c := a - b*2
	
	// If c is negative, set it to 0
	if c < 0 {
		c = 0
	}
	
	// Output the final value of c
	fmt.Println(c)
}
