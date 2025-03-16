package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	INF = 999999999999999999
	MOD = 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer 'n' from input
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])

	// If n is 1, print 0 and exit
	if n == 1 {
		fmt.Println(0)
		return
	}

	// Function to perform prime factorization of a number
	factors := primeFactorize(n)

	// Count the occurrences of each prime factor
	fac := make(map[int]int)
	for _, f := range factors {
		fac[f]++
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of ways to express the prime factors
	for _, e := range fac {
		x := e
		// For each prime factor's exponent, calculate how many times it can be used
		for i := 1; i < 99999999; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to perform prime factorization of a number
func primeFactorize(n int) []int {
	var factors []int

	// Divide n by 2 until it is odd
	for n%2 == 0 {
		factors = append(factors, 2)
		n /= 2
	}

	// Check for odd factors from 3 upwards
	for f := 3; f*f <= n; f += 2 {
		for n%f == 0 {
			factors = append(factors, f)
			n /= f
		}
	}

	// If n is still greater than 1, it is a prime factor
	if n > 1 {
		factors = append(factors, n)
	}

	return factors
}
