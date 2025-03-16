package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	s := input[:len(input)-1] // Remove the newline character
	l := 2019

	// Initialize a slice to count occurrences of remainders, and variables for accumulated value and result
	m := make([]int, l)
	m[0] = 1
	a := 0
	r := 0

	// Iterate over the input string in reverse order
	for i := len(s) - 1; i >= 0; i-- {
		e := s[i]
		// Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
		a += int(e-'0') * powMod(10, len(s)-1-i, l)
		a %= l

		// Update the result 'r' by adding the count of occurrences of the current remainder
		r += m[a]

		// Increment the count of the current remainder in the slice 'm'
		m[a]++
	}

	// Print the final result
	fmt.Println(r)
}

// Helper function to calculate (base^exp) % mod using binary exponentiation
func powMod(base, exp, mod int) int {
	result := 1
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}

