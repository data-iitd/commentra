package main

import (
	"fmt"
	"math"
)

// Function to find the smallest divisor of a number
func div(n int) int {
	if n%2 == 0 {
		return 2
	}
	s := int(math.Sqrt(float64(n)))
	for i := 3; i <= s; i += 2 {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main() {
	var num int
	fmt.Scan(&num) // Read an integer from the user
	fmt.Print(num, ":")

	for num != 1 {
		fmt.Print(" ", div(num)) // Print the smallest divisor and update the number
		num = num / div(num)     // Divide the number by its smallest divisor
	}
	fmt.Println()
}

