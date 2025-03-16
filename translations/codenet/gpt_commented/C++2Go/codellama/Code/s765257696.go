package main

import (
	"fmt"
)

func main() {
	// Optimize input/output operations
	fmt.Println("Enter the number of elements:")
	var n int
	fmt.Scan(&n)

	p := make([]int, n)
	fmt.Println("Enter the elements:")
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	ans := 0
	for i := 0; i < n-2; i++ {
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			ans++
		}
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			ans++
		}
	}

	fmt.Println("The number of valid triplets is:", ans)
}

