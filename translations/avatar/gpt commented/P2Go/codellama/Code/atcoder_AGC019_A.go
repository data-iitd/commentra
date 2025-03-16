
package main

import (
	"fmt"
	"math"
)

// Function to read a line of input
func input() string {
	var line string
	fmt.Scanln(&line)
	return line
}

// Function to compute the ceiling of a divided by b
func ceil(a, b int) int {
	return int(-( -a / b))
}

// Function to round a number to the nearest integer
func round(x float64) int {
	return int((x * 2 + 1) / 2)
}

// Function to compute Fermat's little theorem for modular inverse
func fermat(x, y, MOD int) int {
	return x * int(math.Pow(float64(y), float64(MOD-2))) % MOD
}

// Function to compute the least common multiple of two numbers
func lcm(x, y int) int {
	return (x * y) / gcd(x, y)
}

// Function to compute the least common multiple of a list of numbers
func lcm_list(nums []int) int {
	var result int = 1
	for _, num := range nums {
		result = lcm(result, num)
	}
	return result
}

// Function to read an integer from input
func INT() int {
	var line string
	fmt.Scanln(&line)
	return int(line)
}

// Function to read a list of integers from input
func MAP() []int {
	var line string
	fmt.Scanln(&line)
	var nums []int
	for _, num := range strings.Split(line, " ") {
		nums = append(nums, int(num))
	}
	return nums
}

// Function to read a list of integers into a list
func LIST() []int {
	var line string
	fmt.Scanln(&line)
	var nums []int
	for _, num := range strings.Split(line, " ") {
		nums = append(nums, int(num))
	}
	return nums
}

// Set the maximum recursion limit
func setrecursionlimit(n int) {
	var maxStackSize int = 1000000000
	if n > maxStackSize {
		n = maxStackSize
	}
	var stack [maxStackSize]uintptr
	runtime.Stack(stack[:], false)
}

// Define constants for infinity and modulo
const INF float64 = math.Inf(1)
const MOD int = 1000000007

// Read input values for costs of different types of drinks
q, h, s, d := MAP()

// Read the number of drinks to be purchased
n := INT()

// Calculate the best price for 1 liter of drink
best1L := min(q * 4, h * 2, s)

// Calculate the best price for 2 liters of drink
best2L := min(d, best1L * 2)

// Calculate and print the total cost based on whether n is even or odd
if n % 2 == 0 {
	fmt.Println(best2L * (n / 2))  // Total cost for even number of drinks
} else {
	fmt.Println(best2L * (n / 2) + best1L)  // Total cost for odd number of drinks
}

