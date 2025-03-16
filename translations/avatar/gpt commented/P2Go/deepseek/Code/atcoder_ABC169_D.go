package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read an integer 'n' from input
	n, _ := strconv.Atoi(readLine(reader))

	// If n is 1, print 0 and exit
	if n == 1 {
		fmt.Println(0)
		return
	}

	// Function to perform prime factorization of a number
	primeFactorize := func(n int) []int {
		a := []int{}
		// Divide n by 2 until it is odd
		for n%2 == 0 {
			a = append(a, 2)
			n /= 2
		}

		// Check for odd factors from 3 upwards
		f := 3
		for f*f <= n {
			if n%f == 0 {
				a = append(a, f)
				n /= f
			} else {
				f += 2
			}
		}

		// If n is still greater than 1, it is a prime factor
		if n > 1 {
			a = append(a, n)
		}
		return a
	}

	// Perform prime factorization on n
	fac := primeFactorize(n)

	// Count the occurrences of each prime factor
	facCount := make(map[int]int)
	for _, p := range fac {
		facCount[p]++
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of ways to express the prime factors
	for p, e := range facCount {
		x := e
		// For each prime factor's exponent, calculate how many times it can be used
		for i := 1; ; i++ {
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
