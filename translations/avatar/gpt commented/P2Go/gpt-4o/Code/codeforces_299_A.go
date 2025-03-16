package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the input from the first line
	var input string
	fmt.Scanln(&input)

	// Split the input into a slice of strings and convert to integers
	strArr := strings.Fields(input)
	var a []int
	for _, str := range strArr {
		num, _ := strconv.Atoi(str)
		a = append(a, num)
	}

	// Sort the slice of integers
	sort.Ints(a)

	// Check if any element in the slice 'a' is not divisible by the first element of 'a'
	isDivisible := true
	for _, x := range a {
		if x%a[0] != 0 {
			isDivisible = false
			break
		}
	}

	// Print the first element if all are divisible, otherwise print -1
	if isDivisible {
		fmt.Println(a[0])
	} else {
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
