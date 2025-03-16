package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of integers from input
func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		ints = append(ints, num)
	}
	return ints
}

// Function to read a line of integers from input and convert them to zero-based index
func readIntsZeroBased() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		ints = append(ints, num-1)
	}
	return ints
}

// Function to read a line of floats from input
func readFloats() []float64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	floats := []float64{}
	for _, part := range parts {
		num, _ := strconv.ParseFloat(part, 64)
		floats = append(floats, num)
	}
	return floats
}

// Function to read a line of strings from input
func readStrings() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return strings.Split(scanner.Text(), " ")
}

// Function to read a single integer from input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Function to read a single float from input
func readFloat() float64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

// Function to read a single string from input
func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to print a string and flush the output buffer
func printFlush(s string) {
	fmt.Println(s)
	fmt.Printf("\r")
}

// Main function to process the input and return the result
func main() {
	// Reading a string from input
	s := readString()
	// Reading an integer k from input
	k := readInt()
	l := 0 // Initialize a counter for leading '1's

	// Count the number of leading '1's in the string
	for _, c := range s {
		if c != '1' {
			break
		}
		l++
	}

	// If the count of leading '1's is greater than or equal to k, return 1
	if l >= k {
		fmt.Println(1)
		return
	}

	// Otherwise, return the character at position l in the string
	fmt.Println(string(s[l]))
}

