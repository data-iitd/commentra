
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Function to find the smallest divisor of n
func div(n int) int {
	// Check if n is even, return 2 if it is
	if n%2 == 0 {
		return 2
	}

	// Calculate the square root of n for optimization
	s := int(math.Sqrt(float64(n)))

	// Check for odd divisors from 3 up to the square root of n
	for i := 3; i <= s; i += 2 {
		// If i is a divisor of n, return it
		if n%i == 0 {
			return i
		}
	}

	// If no divisors found, return n (n is prime)
	return n
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Enter an integer:")
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())

	fmt.Print(num, ":")

	// Loop until num is reduced to 1
	for num!= 1 {
		// Find and output the smallest divisor of num
		fmt.Printf(" %d", div(num))
		// Divide num by its smallest divisor
		num = num / div(num)
	}
	fmt.Println()
}

