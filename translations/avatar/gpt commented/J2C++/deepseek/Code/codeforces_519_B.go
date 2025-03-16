package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Initialize variables to hold the sums of three different sets of integers
	var a, b, c int
	
	// Read n integers and calculate their sum (a)
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a += num
	}
	
	// Read n-1 integers and calculate their sum (b)
	for i := 0; i < n - 1; i++ {
		var num int
		fmt.Scan(&num)
		b += num
	}
	
	// Read n-2 integers and calculate their sum (c)
	for i := 0; i < n - 2; i++ {
		var num int
		fmt.Scan(&num)
		c += num
	}
	
	// Calculate the difference between the sums: x = sum of first set - sum of second set
	x := a - b
	
	// Calculate the difference between the sums: y = sum of second set - sum of third set
	y := b - c
	
	// Print the results of the differences
	fmt.Println(x)
	fmt.Println(y)
}
