package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	
	// Split the input string into a slice of strings
	strSlice := strings.Split(input, " ")
	
	// Create a slice to hold the integers
	a := make([]int, len(strSlice))
	
	// Convert the string slice to an integer slice
	for i, str := range strSlice {
		num, _ := strconv.Atoi(str)
		a[i] = num
	}
	
	// Iterate over the integer slice to find the first zero
	for e, i := range a {
		if i == 0 {
			fmt.Println(e + 1)
			break
		}
	}
}

// <END-OF-CODE>
