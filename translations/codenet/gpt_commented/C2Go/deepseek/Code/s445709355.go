package main

import (
	"bufio"
	"fmt"
	"os"
)

// Fast input function to read a character from standard input
var reader = bufio.NewReader(os.Stdin)

// Function to read a non-negative integer from input
func in() int {
	n := 0
	c, _ := reader.ReadByte()
	for c >= '0' {
		n = n*10 + int(c-'0')
		c, _ = reader.ReadByte()
	}
	return n
}

// Arrays to store frequency counts for two different calculations
var f1 [100]int
var f2 [100]int

// Function to calculate frequency counts based on the input number
func calc(n int) {
	k := n % 10
	for n >= 10 {
		n /= 10
	}
	f1[10*k+n]++
	f2[n*10+k]++
}

func main() {
	var i, N, ans int

	// Read the total number of inputs
	N = in()

	// Process each number from N down to 1
	for N > 0 {
		calc(N)
		N--
	}

	ans = 0
	// Calculate the final answer by summing the products of corresponding frequencies
	for i = 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}

	// Output the final answer
	fmt.Println(ans)
}

