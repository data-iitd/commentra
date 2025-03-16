package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println((n*2 + 1) / 3)
}

func factorial(n int) int {
	if n == 0 {
		return 1
	} else {
		return n * factorial(n-1)
	}
}

func main() {
	var number int
	fmt.Scan(&number)
	result := factorial(number)
	fmt.Println(result)
}

func fibonacci(n int) int {
	if n <= 0 {
		return 0
	} else if n == 1 {
		return 1
	} else {
		a, b := 0, 1
		for i := 2; i <= n; i++ {
			a, b = b, a+b
		}
		return b
	}
}

func main() {
	var index int
	fmt.Scan(&index)
	fmt.Println(fibonacci(index))
}
