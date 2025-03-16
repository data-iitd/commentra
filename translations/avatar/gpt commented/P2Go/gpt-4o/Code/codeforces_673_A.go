package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Read the next line of input, split it by spaces, convert each element to an integer, and store it in a slice
	var arr []int
	var input string
	fmt.Scanln(&input)
	for _, s := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(s)
		arr = append(arr, num)
	}

	// Check if the first element of the array is greater than 15
	if arr[0] > 15 {
		// If true, print 15 as the output
		fmt.Println(15)
	} else {
		// Iterate through the array starting from the second element
		for i := 1; i < len(arr); i++ {
			// Check if the difference between the current and previous element is greater than 15
			if arr[i]-arr[i-1] > 15 {
				// If true, print the previous element plus 15 and exit the loop
				fmt.Println(arr[i-1] + 15)
				return
			}
		}
		// If no break occurred, check the last element of the array
		if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
			// If the last element is 90 or adding 15 to it results in 90 or more, print 90
			fmt.Println(90)
		} else {
			// Otherwise, print the last element plus 15
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}
}
// <END-OF-CODE>
