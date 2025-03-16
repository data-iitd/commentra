package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Function to read a line of input
func input() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

// Function to compute the ceiling of a divided by b
func ceil(a, b int) int {
	return int(-( -a / b))
}

// Function to round a number to the nearest integer
func round(x float64) int {
	return int((x*2 + 1) / 2)
}

// Function to compute Fermat's little theorem for modular inverse
func fermat(x, y, MOD int) int {
	return x * powMod(y, MOD-2, MOD) % MOD
}

// Function to compute the least common multiple of two numbers
func lcm(x, y int) int {
	return (x * y) / gcd(x, y)
}

// Function to compute the least common multiple of a list of numbers
func lcmList(nums []int) int {
	lcm := 1
	for _, num := range nums {
		lcm = lcm * num / gcd(lcm, num)
	}
	return lcm
}

// Function to read an integer from input
func INT() int {
	num, _ := strconv.Atoi(input())
	return num
}

// Function to read a list of integers from input
func MAP() []int {
	parts := input()
	nums := []int{}
	for _, part := range parts {
		nums = append(nums, int(part-'0'))
	}
	return nums
}

// Function to read a list of integers into a list
func LIST() []int {
	parts := input()
	nums := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(string(part))
		nums = append(nums, num)
	}
	return nums
}

// Set the maximum recursion limit
func setRecursionLimit() {
	// Go does not have a fixed recursion limit like Python
}

// Define constants for infinity and modulo
const (
	INF  = math.MaxInt64
	MOD  = 1000000007
)

// Main function
func main() {
	// Read input values for costs of different types of drinks
	parts := MAP()
	q, h, s, d := parts[0], parts[1], parts[2], parts[3]

	// Read the number of drinks to be purchased
	n := INT()

	// Calculate the best price for 1 liter of drink
	best1L := min(q*4, h*2, s)

	// Calculate the best price for 2 liters of drink
	best2L := min(d, best1L*2)

	// Calculate and print the total cost based on whether n is even or odd
	if n%2 == 0 {
		fmt.Println(best2L * (n / 2)) // Total cost for even number of drinks
	} else {
		fmt.Println(best2L * (n / 2) + best1L) // Total cost for odd number of drinks
	}
}

// Helper function to compute x^y % mod
func powMod(x, y, mod int) int {
	result := 1
	for y > 0 {
		if y%2 == 1 {
			result = (result * x) % mod
		}
		x = (x * x) % mod
		y /= 2
	}
	return result
}

// Helper function to compute gcd of two numbers
func gcd(x, y int) int {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

