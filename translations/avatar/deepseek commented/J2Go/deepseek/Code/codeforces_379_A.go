package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read the first and second integer inputs
	res := a

	// Enter a while loop that continues as long as a is greater than or equal to b
	for a >= b {
		res += a / b
		a = (a / b) + (a % b)
	}

	fmt.Println(res) // Print the final value of res
}
