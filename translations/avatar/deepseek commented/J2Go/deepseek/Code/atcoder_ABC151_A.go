package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a single line of input from the user
	input, _ := reader.ReadString('\n')

	// Increment the first character of the input by 1 and print it
	fmt.Printf("%c", input[0]+1)
}

type RemRing struct {
	module int64
}

// Constructor to initialize the module value
func NewRemRing(module int64) *RemRing {
	return &RemRing{module: module}
}

// Method to calculate the sum modulo module
func (r *RemRing) Sum(a, b int64) int64 {
	return (a + b + r.module) % r.module
}

// Method to calculate the difference modulo module
func (r *RemRing) Sub(a, b int64) int64 {
	return (a - b + r.module) % r.module
}

// Method to calculate the product modulo module
func (r *RemRing) Prod(a, b int64) int64 {
	return (a * b) % r.module
}

// Method to calculate the division modulo module
func (r *RemRing) Div(a, b int64) int64 {
	return (a * r.Inv(b)) % r.module
}

// Method to calculate the modular inverse
func (r *RemRing) Inv(a int64) int64 {
	b := r.module
	u := int64(1)
	v := int64(0)

	// Extended Euclidean Algorithm to find the modular inverse
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

	u %= r.module
	if u < 0 {
		u += r.module
	}
	return u
}

