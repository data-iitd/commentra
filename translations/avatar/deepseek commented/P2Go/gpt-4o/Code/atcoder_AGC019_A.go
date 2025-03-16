package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(x, y int) int {
	return (x * y) / gcd(x, y)
}

func lcmList(nums []int) int {
	result := 1
	for _, num := range nums {
		result = lcm(result, num)
	}
	return result
}

func main() {
	var q, h, s, d, n int
	fmt.Scan(&q, &h, &s, &d, &n)

	// Calculating the best price for single liters
	best1L := int(math.Min(float64(q*4), math.Min(float64(h*2), float64(s))))

	// Calculating the best price for double liters
	best2L := int(math.Min(float64(d), float64(best1L*2)))

	// Checking if the quantity n is even or odd and printing the total cost accordingly
	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

// <END-OF-CODE>
