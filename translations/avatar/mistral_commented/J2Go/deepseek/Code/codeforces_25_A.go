package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	array := make([]int, n+1)

	// Reading the elements of the array from user input
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i])
	}

	odd, even := 0, 0
	oddIndex, evenIndex := 0, 0

	// Counting the number of odd and even elements and storing their indices
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 {
			even++
			evenIndex = i
		} else {
			odd++
			oddIndex = i
		}
	}

	// Determining the output based on the count of odd and even elements
	if odd > even {
		fmt.Println(evenIndex)
	} else {
		fmt.Println(oddIndex)
	}
}
