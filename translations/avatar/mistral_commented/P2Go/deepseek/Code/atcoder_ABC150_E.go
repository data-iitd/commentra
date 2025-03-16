package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer n from the standard input
	n, _ := strconv.Atoi(readLine(reader))

	// Read n integers from the standard input and store them in a slice c in descending order
	c := readInts(reader)
	sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })

	// Calculate the value of b using the formula 2^(2*n-2) modulo mod
	b := powMod(2, 2*n-2, mod)

	// Calculate the value of a as 2*b modulo mod
	a := 2 * b % mod

	// Initialize the variable ans to zero
	ans := 0

	// Iterate through each index i from 0 to n-1 in the slice c
	for i := 0; i < n; i++ {
		// Add the product of the current element c[i] and the sum of a and i*b to the variable ans
		ans += c[i] * (a + i*b)
		// Update the value of ans by taking the modulo of the current sum with mod
		ans %= mod
	}

	// Print the value of ans as the output
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	ints := []int{}
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

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

