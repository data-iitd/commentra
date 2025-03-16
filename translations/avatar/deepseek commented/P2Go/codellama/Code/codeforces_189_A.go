package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func cutRibbon() {
	// Take input from the user, which is expected to be a list of three integers
	arr := strings.Split(input(), " ")

	// Assign the first integer in the input list to the variable 'length'
	length, _ := strconv.Atoi(arr[0])

	// Sort the remaining three integers in ascending order and assign to 'arr'
	arr = arr[1:]
	sort.Ints(arr)

	// Check if 'length' is perfectly divisible by the largest integer in 'arr'
	if length%arr[0] == 0 {
		// Print the quotient and return if true
		fmt.Println(length / arr[0])
		return
	}

	// Initialize 'ans' to 0 for storing the maximum number of ribbons
	ans := 0

	// If the two smaller integers are equal, proceed with this block
	if arr[0] == arr[1] {
		k := 0
		// Iterate through possible combinations of the two smaller integers
		for i := 0; i <= int(length/arr[2]); i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k = check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		// If the two smaller integers are not equal, iterate through all three integers
		k := 0
		for i := 0; i <= int(length/arr[2]); i++ {
			for j := 0; j <= int(length/arr[1]); j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k = check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}

	// Print the maximum number of ribbons that can be cut and return
	fmt.Println(ans)
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

func main() {
	cutRibbon()
}

// 