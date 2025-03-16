package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Main function to solve the problem
func solve() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t := ""
	i := 0

	// Process the input string character by character
	for i < len(s) {
		if s[i] == 'A' {
			t += "A"
			i++
		} else if s[i] == 'B' {
			if i < len(s)-1 {
				if s[i+1] == 'C' {
					t += "D"
					i += 2
				} else {
					t += "X"
					i++
				}
			} else {
				t += "X"
				i++
			}
		} else {
			t += "X"
			i++
		}
	}

	total := 0
	numA := 0

	// Count the number of 'A' characters before each 'X' in the processed string
	for i := 0; i < len(t); i++ {
		if t[i] == 'X' {
			numA = 0
		} else {
			if t[i] == 'A' {
				numA++
			} else {
				total += numA
			}
		}
	}

	fmt.Println(total)

	// Define constants for infinity and modulo
	const INF = 100000000000000000000000000
	const mod = 7 + 1000000000
}

func main() {
	solve()
}
