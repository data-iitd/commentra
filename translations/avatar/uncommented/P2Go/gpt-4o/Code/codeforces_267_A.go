package main

import (
	"fmt"
)

func subtract(a, b int) int {
	if a > b {
		total := 0
		for a > 0 && b > 0 {
			total += a / b
			a = a % b
			if a > 0 {
				total += b / a
				b = b % a
			}
		}
		return total
	}
	if a < b {
		total := 0
		for a > 0 && b > 0 {
			total += b / a
			b = b % a
			if b > 0 {
				total += a / b
				a = a % b
			}
		}
		return total
	}
	if a == b {
		return 1
	}
	return 0 // This line is added to handle the case when a and b are both zero
}

func main() {
	var n int
	fmt.Scan(&n)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		lst[i] = subtract(a, b)
	}
	for _, value := range lst {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
