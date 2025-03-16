
package main

import "fmt"

// Direction vectors for moving in 4 directions (up, right, down, left)
var dy = []int{-1, 0, +1, 0}
var dx = []int{0, +1, 0, -1}

// Constants for infinity and modulo operations
const INF = 1 << 60
const MOD = 1e9 + 7

// Function to compute the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to compute the binary representation of a number
func toBinary(n int) string {
	var s string
	for n!= 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}
		n -= abs(n%2)
		n /= -2
	}
	return s
}

// Main function
func main() {
	var n int
	fmt.Scanf("%d", &n)
	if n == 0 {
		fmt.Println("0")
		return
	}
	s := toBinary(n)
	reverse(s)
	fmt.Println(s)
}

