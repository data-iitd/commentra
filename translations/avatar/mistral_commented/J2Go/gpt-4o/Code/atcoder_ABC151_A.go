package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a new BufferedReader object to read input
	s, _ := reader.ReadString('\n')      // Read a line of input
	fmt.Printf("%c", s[0]+1)             // Print the ASCII value of the first character incremented by 1
}

type RemRing struct { // Define a new struct named RemRing
	module int64 // Declare a long variable named module to store the ring modulus
}

func NewRemRing(module int64) *RemRing { // Constructor to initialize the module variable
	return &RemRing{module: module}
}

func (r *RemRing) Sum(a, b int64) int64 { // Method to compute the sum of two numbers modulo the module
	return (a + b + r.module) % r.module
}

func (r *RemRing) Sub(a, b int64) int64 { // Method to compute the difference of two numbers modulo the module
	return (a - b + r.module) % r.module
}

func (r *RemRing) Prod(a, b int64) int64 { // Method to compute the product of two numbers modulo the module
	return (a * b) % r.module
}

func (r *RemRing) Div(a, b int64) int64 { // Method to compute the quotient of two numbers modulo the module
	quotient := a * r.Inv(b) // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
	return quotient % r.module // Return the quotient modulo the module
}

func (r *RemRing) Inv(a int64) int64 { // Method to compute the multiplicative inverse of a number modulo the module
	b := r.module // Initialize b as the module
	u := int64(1) // Initialize u as 1
	v := int64(0) // Initialize v as 0

	// Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
	for b > 0 {
		t := a / b // Compute the quotient of a divided by b
		z := a    // Store a temporarily
		a = b    // Update a with the value of b
		b = z % r.module // Update b with the remainder of z modulo the module
		temp := u // Store u temporarily
		u = v    // Update u with the value of v
		v = temp - t*v // Update v as (u - t * v) % module
	}

	// If the result is negative, add the module to make it positive
	if u < 0 {
		u += r.module
	}

	return u // Return the multiplicative inverse of a
}

// <END-OF-CODE>
