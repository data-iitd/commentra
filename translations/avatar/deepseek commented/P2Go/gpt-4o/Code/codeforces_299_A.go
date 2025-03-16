package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the first integer input (not used in the logic)

	var input string
	fmt.Scan(&input) // Read the second line of input

	// Split the input string into a slice of strings and convert to integers
	strArr := strings.Split(input, " ")
	arr := make([]int, len(strArr))
	for i, str := range strArr {
		num, _ := strconv.Atoi(str)
		arr[i] = num
	}

	// Sort the array
	sort.Ints(arr)

	// Check if the smallest element is divisible by any other element
	smallest := arr[0]
	isDivisible := false
	for _, x := range arr {
		if x != smallest && x%smallest == 0 {
			isDivisible = true
			break
		}
	}

	// Print the result
	if isDivisible {
		fmt.Println(smallest)
	} else {
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
