package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)  // Taking an integer input `n` which represents the number of iterations.
	for i := 0; i < n; i++ {  // Looping `n` times.
		var a int
		fmt.Scan(&a)  // Taking an integer input `a` for each iteration.
		if a < 2 {  // Checking if `a` is less than 2.
			fmt.Println(0)  // Printing 0 if `a` is less than 2.
		} else {  // If `a` is not less than 2.
			fmt.Println(a - 2)  // Printing the result of `a - 2`.
		}
	}
}
