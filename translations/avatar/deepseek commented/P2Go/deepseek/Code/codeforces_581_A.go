package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	factorial := 1
	for i := 1; i <= n; i++ {
		factorial *= i
	}
	fmt.Println(factorial)
}

