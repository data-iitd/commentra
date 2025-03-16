package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n string
	fmt.Scan(&n)  // Taking an input from the user and storing it in the variable `n`.
	a := []string{"10", "100", "1000", "10000", "100000"}  // Defining a slice `a` containing string representations of numbers.
	var new int
	for _, digit := range n {
		num, _ := strconv.Atoi(string(digit))  // Converting each character of `n` to an integer.
		new += num  // Summing up the digits and storing the result in `new`.
	}
	if contains(a, n) {  // Checking if the input `n` is in the slice `a`.
		fmt.Println(10)  // If `n` is in `a`, print the number 10.
	} else {  // Otherwise...
		fmt.Println(new)  // Print the value of `new`.
	}
}

func contains(slice []string, item string) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}
