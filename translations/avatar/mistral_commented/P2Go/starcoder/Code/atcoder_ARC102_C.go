// Package main runs the solution to the problem.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a constant N for the size of the arrays
const N = 8000

// Define a function to compute the number of combinations of r items chosen from a set of n items, modulo a given modulus
func cmb(n, r, mod int) int {
	// Check if r is out of range
	if r < 0 || r > n {
		return 0
	}
	// Adjust r to be between 0 and n
	r = min(r, n - r)
	// Compute the combination using the formula
	return g1[n] * g2[r] * g2[n-r] % mod
}

// Define a function to compute the value of a combinatorial sum
func kumiawase(p, q int) int {
	// Compute the combination using the cmb function
	return cmb(p+q-1, q-1, mod)
}

// Define a function to compute the answer for a given value of n
func solve(n int) int {
	// Check if n is out of range
	if n > K+1 {
		return 0
	}
	// Initialize the answer as 0
	ans := 0
	// Compute the number of pairs (p, q) such that p <= N and q <= K - p
	kumi := (n-1) / 2
	// Compute the answer using the kumiawase function and the precomputed values
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-n%2==0))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-n%2==0))
	}
	// Return the answer
	return ans
}

// Define a function to print arguments with a space between them
func dprint(x...interface{}) {
	fmt.Fprint(os.Stderr, x...)
}

// Define a function to read an integer from the standard input
func readInt(b *bufio.Reader) (int, error) {
	var x int
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return 0, err
		}
		if c =='' {
			return x, nil
		}
		x = x*10 + int(c-'0')
	}
}

// Define a function to read a slice of integers from the standard input
func readInts(b *bufio.Reader) ([]int, error) {
	var x []int
	for {
		var v int
		v, err := readInt(b)
		if err!= nil {
			return nil, err
		}
		x = append(x, v)
	}
}

// Define a function to read a line from the standard input
func readLine(b *bufio.Reader) (string, error) {
	var x string
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return "", err
		}
		if c == '\n' {
			return x, nil
		}
		x += string(c)
	}
}

// Define a function to print arguments with a space between them
func dprint(x...interface{}) {
	fmt.Fprint(os.Stderr, x...)
}

// Define a function to read an integer from the standard input
func readInt(b *bufio.Reader) (int, error) {
	var x int
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return 0, err
		}
		if c =='' {
			return x, nil
		}
		x = x*10 + int(c-'0')
	}
}

// Define a function to read a slice of integers from the standard input
func readInts(b *bufio.Reader) ([]int, error) {
	var x []int
	for {
		var v int
		v, err := readInt(b)
		if err!= nil {
			return nil, err
		}
		x = append(x, v)
	}
}

// Define a function to read a line from the standard input
func readLine(b *bufio.Reader) (string, error) {
	var x string
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return "", err
		}
		if c == '\n' {
			return x, nil
		}
		x += string(c)
	}
}

// Define a function to compute the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// Define a function to compute the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Define a function to compute the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Define a function to compute the sign of an integer
func sign(x int) int {
	if x < 0 {
		return -1
	}
	if x > 0 {
		return 1
	}
	return 0
}

// Define a function to compute the GCD of two integers
func gcd(x, y int) int {
	for y!= 0 {
		x, y = y, x%y
	}
	return x
}

// Define a function to compute the LCM of two integers
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// Define a function to compute the factorial of an integer
func fact(x int) int {
	if x <= 1 {
		return 1
	}
	return x * fact(x-1)
}

// Define a function to compute the inverse of an integer modulo a modulus
func inv(x, mod int) int {
	return pow(x, mod-2, mod)
}

// Define a function to compute the power of an integer modulo a modulus
func pow(x, y, mod int) int {
	if y == 0 {
		return 1
	}
	if y == 1 {
		return x
	}
	if y%2 == 0 {
		return pow(x*x%mod, y/2, mod)
	}
	return x * pow(x*x%mod, y/2, mod) % mod
}

// Define a function to compute the value of a combinatorial sum
func kumiawase(p, q int) int {
	// Compute the combination using the cmb function
	return cmb(p+q-1, q-1, mod)
}

// Define a function to compute the answer for a given value of n
func solve(n int) int {
	// Check if n is out of range
	if n > K+1 {
		return 0
	}
	// Initialize the answer as 0
	ans := 0
	// Compute the number of pairs (p, q) such that p <= N and q <= K - p
	kumi := (n-1) / 2
	// Compute the answer using the kumiawase function and the precomputed values
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-n%2==0))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-n%2==0))
	}
	// Return the answer
	return ans
}

// Define a function to print arguments with a space between them
func dprint(x...interface{}) {
	fmt.Fprint(os.Stderr, x...)
}

// Define a function to read an integer from the standard input
func readInt(b *bufio.Reader) (int, error) {
	var x int
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return 0, err
		}
		if c =='' {
			return x, nil
		}
		x = x*10 + int(c-'0')
	}
}

// Define a function to read a slice of integers from the standard input
func readInts(b *bufio.Reader) ([]int, error) {
	var x []int
	for {
		var v int
		v, err := readInt(b)
		if err!= nil {
			return nil, err
		}
		x = append(x, v)
	}
}

// Define a function to read a line from the standard input
func readLine(b *bufio.Reader) (string, error) {
	var x string
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return "", err
		}
		if c == '\n' {
			return x, nil
		}
		x += string(c)
	}
}

// Define a function to compute the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// Define a function to compute the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Define a function to compute the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Define a function to compute the sign of an integer
func sign(x int) int {
	if x < 0 {
		return -1
	}
	if x > 0 {
		return 1
	}
	return 0
}

// Define a function to compute the GCD of two integers
func gcd(x, y int) int {
	for y!= 0 {
		x, y = y, x%y
	}
	return x
}

// Define a function to compute the LCM of two integers
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// Define a function to compute the factorial of an integer
func fact(x int) int {
	if x <= 1 {
		return 1
	}
	return x * fact(x-1)
}

// Define a function to compute the inverse of an integer modulo a modulus
func inv(x, mod int) int {
	return pow(x, mod-2, mod)
}

// Define a function to compute the power of an integer modulo a modulus
func pow(x, y, mod int) int {
	if y == 0 {
		return 1
	}
	if y == 1 {
		return x
	}
	if y%2 == 0 {
		return pow(x*x%mod, y/2, mod)
	}
	return x * pow(x*x%mod, y/2, mod) % mod
}

// Define a function to compute the value of a combinatorial sum
func kumiawase(p, q int) int {
	// Compute the combination using the cmb function
	return cmb(p+q-1, q-1, mod)
}

// Define a function to compute the answer for a given value of n
func solve(n int) int {
	// Check if n is out of range
	if n > K+1 {
		return 0
	}
	// Initialize the answer as 0
	ans := 0
	// Compute the number of pairs (p, q) such that p <= N and q <= K - p
	kumi := (n-1) / 2
	// Compute the answer using the kumiawase function and the precomputed values
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-kumi*2-n%2==0))
		if n%2 == 0 && N-p-1 >= 0 {
			ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-kumi*2-n%2==0))
	}
	// Return the answer
	return ans
}

// Define a function to print arguments with a space between them
func dprint(x...interface{}) {
	fmt.Fprint(os.Stderr, x...)
}

// Define a function to read an integer from the standard input
func readInt(b *bufio.Reader) (int, error) {
	var x int
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return 0, err
		}
		if c =='' {
			return x, nil
		}
		x = x*10 + int(c-'0')
	}
}

// Define a function to read a slice of integers from the standard input
func readInts(b *bufio.Reader) ([]int, error) {
	var x []int
	for {
		var v int
		v, err := readInt(b)
		if err!= nil {
			return nil, err
		}
		x = append(x, v)
	}
}

// Define a function to read a line from the standard input
func readLine(b *bufio.Reader) (string, error) {
	var x string
	for {
		c, err := b.ReadByte()
		if err!= nil {
			return "", err
		}
		if c == '\n' {
			return x, nil
		}
		x += string(c)
	}
}

// Define a function to compute the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// Define a function to compute the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// Define a function to compute the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Define a function to compute the sign of an integer
func sign(x int) int {
	if x < 0 {
		return -1
	}
	if x > 0 {
		return 1
	}
	return 0
}

// Define a function to compute the GCD of two integers
func gcd(x, y int) int {
	for y!= 0 {
		x, y = y, x%y
	}
	return x
}

// Define a function to compute the LCM of two integers
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// Define a function to compute the factorial of an integer
func fact(x int) int {
	if x <= 1 {
		return 1
	}
	return x * fact(x-1)
}

// Define a function to comp