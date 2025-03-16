package main

import (
	"fmt"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	printResult(x, n)
}

func printResult(x, n int) {
	max := n*2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	for i := x + n - 1; i < x+n+max-1; i++ {
		fmt.Println((i%max + 1))
	}
}

// <END-OF-CODE>
