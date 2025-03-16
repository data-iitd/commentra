

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

	// Read a single line of input from the user
	scanner.Scan()
	s := scanner.Text()

	// Increment the first character of the input by 1 and print it
	fmt.Printf("%c", s[0]+1)
}

type RemRing struct {
	module int64
}

// Constructor to initialize the module value
func NewRemRing(module int64) *RemRing {
	return &RemRing{module: module}
}

// Method to calculate the sum modulo module
func (rr *RemRing) Sum(a, b int64) int64 {
	return (a + b + rr.module) % rr.module
}

// Method to calculate the difference modulo module
func (rr *RemRing) Sub(a, b int64) int64 {
	return (a - b + rr.module) % rr.module
}

// Method to calculate the product modulo module
func (rr *RemRing) Prod(a, b int64) int64 {
	return (a * b) % rr.module
}

// Method to calculate the division modulo module
func (rr *RemRing) Div(a, b int64) int64 {
	return (a * rr.Inv(b)) % rr.module
}

// Method to calculate the modular inverse
func (rr *RemRing) Inv(a int64) int64 {
	b := rr.module
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

	u %= rr.module
	if u < 0 {
		u += rr.module
	}
	return u
}

