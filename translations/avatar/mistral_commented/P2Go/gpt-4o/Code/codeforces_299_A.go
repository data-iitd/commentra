package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

// Function to read a single integer input
func numInp() int {
	var input int
	fmt.Scan(&input)
	return input
}

// Function to read a list of integers
func arrInp() []int {
	var input string
	fmt.Scan(&input)
	strs := strings.Split(input, " ")
	arr := make([]int, len(strs))
	for i, s := range strs {
		num, _ := strconv.Atoi(s)
		arr[i] = num
	}
	return arr
}

// Function to read a list of integers from space-separated input
func spInp() []int {
	var input string
	fmt.Scan(&input)
	strs := strings.Split(input, " ")
	arr := make([]int, len(strs))
	for i, s := range strs {
		num, _ := strconv.Atoi(s)
		arr[i] = num
	}
	return arr
}

func main() {
	// Read input from file instead of user input
	var a []int
	var n int
	fmt.Scan(&n) // Read the number of elements
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		a = append(a, num)
	}
	sort.Ints(a) // Sort the list of integers

	// Find the largest number that leaves a remainder when divided by any number in the list
	if len(a) > 0 {
		if anyRemainder(a[0], a) {
			fmt.Println(-1)
		} else {
			fmt.Println(a[0])
		}
	}
}

// Function to check if any number leaves a remainder when divided by the given number
func anyRemainder(divisor int, arr []int) bool {
	for _, x := range arr {
		if x%divisor != 0 {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
