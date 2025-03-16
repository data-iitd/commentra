package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from the console
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to convert a string to a number
func strToNum(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

// Function to convert a number to a string
func numToStr(n int) string {
	return strconv.Itoa(n)
}

// Function to perform modular addition
func sum(a, b, m int) int {
	return (a + b + m) % m
}

// Function to perform modular subtraction
func sub(a, b, m int) int {
	return (a - b + m) % m
}

// Function to perform modular multiplication
func prod(a, b, m int) int {
	return (a * b) % m
}

// Function to perform modular division
func div(a, b, m int) int {
	return (a * inv(b, m)) % m
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
func inv(a, m int) int {
	b := m
	u := 1
	v := 0

	// Extended Euclidean Algorithm to find the inverse
	for b > 0 {
		t := a / b
		a -= t * b
		u -= t * v
		z := a
		a = b
		b = z
		z = u
		u = v
		v = z
	}

	// Ensure the result is positive
	u %= m
	if u < 0 {
		u += m
	}

	// Return the modular inverse
	return u
}

func main() {
	// Read the input
	s := readInput()

	// Convert the input to a number
	a := strToNum(s)

	// Output the next character in the ASCII sequence of the first character of the input
	fmt.Printf("%c", numToStr(a+1)[0])
}

