
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Declare a string to hold the input
	var s string

	// Read a line of input from the user
	if scanner.Scan() {
		s = scanner.Text()
	}

	// Output the next character in the ASCII sequence of the first character of the input
	fmt.Printf("%c", s[0]+1)
}

// Class to perform operations in a modular arithmetic system
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
	u := int64(1)
	v := int64(0)

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
	u %= r.module
	if u < 0 {
		u += r.module
	}

	// Return the modular inverse
	return u
}

// END-OF-CODE