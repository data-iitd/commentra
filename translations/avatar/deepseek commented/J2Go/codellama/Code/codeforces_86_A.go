
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
		a = a / 10
	}
	return res
}

// Function to calculate the maximum product of two numbers formed by splitting the given number into two parts
func mult(a int64) int64 {
	pow := power(a)
	max := int64(0)
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	return a * (max - a)
}

func main() {
	// Read two long integers from the input
	var l, r int64
	fmt.Scan(&l, &r)
	res := int64(0)
	maxxes := make([]int64, 10)
	temp := int64(0)

	// Calculate the maximum product for each range and store it in the array maxxes
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		maxxes[i] = temp/2 * (temp - temp/2)
	}

	// Calculate the maximum product for the given ranges and update the result res
	res = math.Max(mult(l), res)
	res = math.Max(mult(r), res)
	temp = int64(0)

	// Check if the middle value of the range is within the given range and update the result res accordingly
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9
		if l <= temp/2 && temp/2 <= r {
			res = math.Max(maxxes[i], res)
		}
	}

	// Print the final result
	fmt.Println(res)
}

