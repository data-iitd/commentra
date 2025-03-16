package main

import (
	"fmt"
	"math"
)

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
	fmt.Scan(&num)
	fmt.Print(num, ":")

	for num != 1 {
		factor := div(num)
		fmt.Print(" ", factor)
		num = num / factor
	}
	fmt.Println()
}

// <END-OF-CODE>
