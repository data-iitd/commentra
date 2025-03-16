
package main

import "fmt"

func main() {
	var i, N, x int
	x = 0
	fmt.Print("Enter a number: ")
	fmt.Scan(&N)
	for i = 1; i <= N; i++ {
		x += i
	}
	fmt.Printf("The sum of numbers from 1 to %d is: %d\n", N, x)
}

