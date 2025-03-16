package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize sums of subsets
	var a, b, c int
	
	// Sum all n elements
	for i := 0; i < n; i++ {
		scanner.Scan()
		var num int
		fmt.Sscan(scanner.Text(), &num)
		a += num
	}
	
	// Sum n-1 elements
	for i := 0; i < n - 1; i++ {
		scanner.Scan()
		var num int
		fmt.Sscan(scanner.Text(), &num)
		b += num
	}
	
	// Sum n-2 elements
	for i := 0; i < n - 2; i++ {
		scanner.Scan()
		var num int
		fmt.Sscan(scanner.Text(), &num)
		c += num
	}
	
	// Calculate the differences
	x := a - b
	y := b - c
	
	// Output the results
	fmt.Println(x)
	fmt.Println(y)
}
