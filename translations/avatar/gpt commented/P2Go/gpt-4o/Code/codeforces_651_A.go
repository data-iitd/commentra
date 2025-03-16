package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	// Read two integers from input and assign them to x and y
	fmt.Scan(&x, &y)

	// Calculate the maximum value based on the formula and print it
	// The formula computes x + y - 3 and adjusts based on the difference between y and x
	// It ensures the result is not negative by taking the maximum with 0
	result := int(math.Max(float64(x+y-3+((y-x)%3)), 0))
	fmt.Println(result)
}

// Define a function to read a single integer from input
func numInp() int {
	var num int
	fmt.Scan(&num)
	return num
}

// Define a function to read a list of integers from input
func arrInp() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

// Define a function to read a space-separated list of integers from input
func spInp() []int {
	var arr []int
	for {
		var num int
		if _, err := fmt.Scan(&num); err != nil {
			break
		}
		arr = append(arr, num)
	}
	return arr
}

// Define a function to read a string from input
func strInp() string {
	var str string
	fmt.Scan(&str)
	return str
}

// <END-OF-CODE>
