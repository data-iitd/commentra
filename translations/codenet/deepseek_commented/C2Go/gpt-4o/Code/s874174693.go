package main

import (
	"fmt"
)

// Function to calculate the sum of the last 9 digits of a number
func sumOfLastNineDigits(n int) int {
	sum := 0
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}
	return sum
}

// Main function
func main() {
	var n int
	fmt.Scan(&n)
	sum := sumOfLastNineDigits(n)
	if n%sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
