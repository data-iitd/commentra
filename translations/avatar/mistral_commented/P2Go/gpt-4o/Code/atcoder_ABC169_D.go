package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	INF = 999999999999999999999999
	MOD = 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Get the number of test cases
	n, _ := strconv.Atoi(readLine(reader))

	// Base case for the recursion
	if n == 1 {
		fmt.Println(0)
		return
	}

	// Function to prime factorize a number
	fac := primeFactorize(n)
	ans := 0

	// Count the occurrences of each prime factor
	factorCount := make(map[int]int)
	for _, p := range fac {
		factorCount[p]++
	}

	// Calculate the answer
	for p, e := range factorCount {
		x := e
		for i := 1; i < 1000000000; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Function to read a line from the input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1] // Remove the newline character
}

// Function to prime factorize a number
func primeFactorize(n int) []int {
	var factors []int
	for n%2 == 0 {
		factors = append(factors, 2)
		n /= 2
	}
	for f := 3; f*f <= n; f += 2 {
		for n%f == 0 {
			factors = append(factors, f)
			n /= f
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}
