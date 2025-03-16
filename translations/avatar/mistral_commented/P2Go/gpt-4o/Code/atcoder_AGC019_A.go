package main

import (
	"fmt"
	"math"
)

const MOD = 1e9 + 7

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
	var q, h, s, d int
	var n int

	// Read input
	fmt.Scan(&q, &h, &s, &d)
	fmt.Scan(&n)

	// Calculate the length of the longest segment that can be formed
	best1L := int(math.Min(float64(q*4), math.Min(float64(h*2), float64(s))))
	best2L := int(math.Min(float64(d), float64(best1L*2)))

	// Check if n is even
	if n%2 == 0 {
		// If it is, print the length of the longest segment that can be formed
		// by dividing n into pairs and using the best2L length for each pair
		fmt.Println(best2L * (n / 2))
	} else {
		// If n is odd, print the length of the longest segment that can be formed
		// by dividing n-1 into pairs and using the best2L length for each pair,
		// and adding the best1L length at the end
		fmt.Println(best2L*(n/2) + best1L)
	}
}

// <END-OF-CODE>
