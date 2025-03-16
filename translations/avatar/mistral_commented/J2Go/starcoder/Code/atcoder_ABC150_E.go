package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the power of a number x raised to the power n
func power(x, n int) int {
	if n == 0 { // Base case when n is 0
		return 1
	}

	val := power(x, n/2) // Recursively calculating the square of x raised to the power n/2

	// If n is odd, multiplying the result with x
	if n%2 == 1 {
		val = val * x
	}

	return val
}

// Function to sort the array in parallel
func sort(c []int) {
	// Sorting the array c in parallel using sort.Slice() method
	sort.Slice(c, func(i, j int) bool { return c[i] < c[j] })
}

// Function to calculate the value of b and a
func calculate(n int) (int, int) {
	b := power(2, n)
	a := power(2, n-2)
	return b, a
}

// Function to calculate the value of ans
func calculateAns(c []int, n int, b, a int) int {
	ans := 0
	mod := 1000000007

	// Iterating through the array from index 2 to n+1
	for i := 2; i <= n+1; i++ {
		val := a * i % mod // Calculating the value of val using the current index i and the previously calculated value a

		// Multiplying the value of val with the current element of the array c[n+1-i]
		val *= c[n+1-i]

		// Taking the modulus of the product to ensure the result is within the range of modulus
		val %= mod

		// Adding the value of val to the variable ans
		ans += val

		// Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
		ans %= mod
	}

	// Multiplying the value of ans with the value of b
	ans *= b

	// Taking the modulus of the product to ensure the result is within the range of modulus
	ans %= mod

	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort(c)
	b, a := calculate(n)
	ans := calculateAns(c, n, b, a)
	fmt.Println(ans)
}

