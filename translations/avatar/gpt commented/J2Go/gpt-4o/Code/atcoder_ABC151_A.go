package main

import (
	"fmt"
	"bufio"
	"os"
)

// RemRing struct to perform operations in a modular arithmetic system
type RemRing struct {
	module int64 // Variable to store the modulus value
}

// Constructor to initialize the modulus
func NewRemRing(module int64) *RemRing {
	return &RemRing{module: module}
}

// Method to perform modular addition
func (r *RemRing) Sum(a, b int64) int64 {
	return (a + b + r.module) % r.module
}

// Method to perform modular subtraction
func (r *RemRing) Sub(a, b int64) int64 {
	return (a - b + r.module) % r.module
}

// Method to perform modular multiplication
func (r *RemRing) Prod(a, b int64) int64 {
	return (a * b) % r.module
}

// Method to perform modular division
func (r *RemRing) Div(a, b int64) int64 {
	return (a * r.Inv(b)) % r.module
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (r *RemRing) Inv(a int64) int64 {
	b := r.module
	u, v := int64(1), int64(0)

	// Extended Euclidean Algorithm to find the inverse
	for b > 0 {
		t := a / b
		a -= t * b
		u -= t * v
		a, b = b, a
		u, v = v, u
	}

	// Ensure the result is positive
	u %= r.module
	if u < 0 {
		u += r.module
	}

	// Return the modular inverse
	return u
}

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from the user
	s, _ := reader.ReadString('\n')

	// Output the next character in the ASCII sequence of the first character of the input
	fmt.Printf("%c", s[0]+1)
}

// <END-OF-CODE>
