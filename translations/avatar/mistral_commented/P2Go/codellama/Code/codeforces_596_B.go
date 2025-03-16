package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Ask the user for the number of elements in the list
	fmt.Print("Enter the number of elements in the list: ")
	var n int
	fmt.Scan(&n)

	// Ask the user to input the elements of the list separated by spaces
	fmt.Print("Enter the elements of the list separated by spaces: ")
	var r string
	fmt.Scan(&r)

	// Initialize a variable to store the answer
	ans := 0

	// Use a for loop to calculate the sum of the absolute differences between consecutive elements
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(strings.Split(r, " ")[i])
		if i == 0 {
			ans = abs(num)
		} else {
			ans += abs(num - num)
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 