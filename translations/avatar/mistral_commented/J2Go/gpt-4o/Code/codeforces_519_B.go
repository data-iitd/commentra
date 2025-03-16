package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	// Reading the number of test cases (n) from the input

	a, b, c := 0, 0, 0
	// Declaring and initializing three integer variables a, b, and c with zero values

	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a += num
	}
	// Using a for loop to read and sum up the first number in each test case

	for i := 0; i < n-1; i++ {
		var num int
		fmt.Scan(&num)
		b += num
	}
	// Using a for loop to read and sum up the second number in each test case (except the last one)

	for i := 0; i < n-2; i++ {
		var num int
		fmt.Scan(&num)
		c += num
	}
	// Using a for loop to read and sum up the third number in each test case (except the last two)

	x := a - b
	// Calculating the difference between the sum of the first and second number in each test case

	y := b - c
	// Calculating the difference between the sum of the second and third number in each test case

	fmt.Println(x)
	fmt.Println(y)
	// Printing the values of 'x' and 'y' to the standard output
}

// <END-OF-CODE>
