package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read user input and assign it to the variable 'n'
	n, _ := strconv.Atoi(input())

	// Create a list 'list' with the same length as 'n'
	// Each element in the list is the remainder of the corresponding input value divided by 2
	list := make([]int, n)
	for i := 0; i < n; i++ {
		list[i] = int(input()[i]) % 2
	}

	// Check if the sum of all elements in the list is equal to 1
	if sum(list) == 1 {
		// If the condition is true, print the index of the first occurrence of the number 1 in the list
		fmt.Println("The first number with remainder 1 is:", list.Index(1)+1)
	} else {
		// If the condition is false, print the index of the first occurrence of the number 0 in the list
		fmt.Println("The first number with remainder 0 is:", list.Index(0)+1)
	}
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

func sum(list []int) int {
	var sum int
	for _, v := range list {
		sum += v
	}
	return sum
}

// 