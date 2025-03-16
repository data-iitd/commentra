package main

import (
	"fmt"
	"math"
)

// Function to calculate the number of digits in a given long integer
func power(a int64) int {
	res := 0
	for a > 0 {
		res++
		a /= 10
	}
	return res
}

// Function to calculate the maximum product of two numbers formed by splitting the given number into two parts
func mult(a int64) int64 {
	pow := power(int(a))
	max := int64(math.Pow(10, float64(pow)) - 1)
	return a * (max - a)
}

func main() {
	// Read two long integers from the input
	var l, r int64
	fmt.Scan(&l, &r)
	var res int64 = 0
	var maxxes [10]int64
	var temp int64 = 0

	// Calculate the maximum product for each range and store it in the array maxxes
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		maxxes[i] = temp/2 * (temp - temp/2)
	}

	// Calculate the maximum product for the given ranges and update the result res
	res = int64(math.Max(float64(mult(l)), float64(res)))
	res = int64(math.Max(float64(mult(r)), float64(res)))
	temp = 0

	// Check if the middle value of the range is within the given range and update the result res accordingly
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		if l <= temp/2 && temp/2 <= r {
			res = int64(math.Max(float64(maxxes[i]), float64(res)))
		}
	}

	// Print the final result
	fmt.Println(res)
}
