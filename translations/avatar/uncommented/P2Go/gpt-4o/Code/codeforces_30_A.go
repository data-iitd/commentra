package main

import (
	"fmt"
	"strconv"
)

func task4(A, B, n int) int {
	for X := -1000; X <= 1000; X++ {
		if A*(X^n) == B {
			return X
		}
	}
	return -1 // Indicating no solution found
}

func main() {
	var A, B, n string
	fmt.Scan(&A, &B, &n)

	a, _ := strconv.Atoi(A)
	b, _ := strconv.Atoi(B)
	nValue, _ := strconv.Atoi(n)

	result := task4(a, b, nValue)
	if result == -1 {
		fmt.Println("No solution")
	} else {
		fmt.Println(result)
	}
}

// <END-OF-CODE>
