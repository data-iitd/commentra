package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a BufferedReader to read input from the console
	r := bufio.NewReader(os.Stdin)

	// Declare a string to hold the input
	var s string

	// Read a line of input from the user
	s, _ = r.ReadString('\n')

	// Output the next character in the ASCII sequence of the first character of the input
	fmt.Printf("%c", s[0]+1)
}

// Class to perform operations in a modular arithmetic system
type RemRing struct {
	module int64
}

// Constructor to initialize the modulus
func (rr *RemRing) Init(module int64) {
	rr.module = module
}

// Method to perform modular addition
func (rr *RemRing) Sum(a, b int64) int64 {
	return (a + b + rr.module) % rr.module
}

// Method to perform modular subtraction
func (rr *RemRing) Sub(a, b int64) int64 {
	return (a - b + rr.module) % rr.module
}

// Method to perform modular multiplication
func (rr *RemRing) Prod(a, b int64) int64 {
	return (a * b) % rr.module
}

// Method to perform modular division
func (rr *RemRing) Div(a, b int64) int64 {
	return (a * rr.inv(b)) % rr.module
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) Inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
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
	u %= rr.module
	if u < 0 {
		u += rr.module
	}

	// Return the modular inverse
	return u
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
	u := 