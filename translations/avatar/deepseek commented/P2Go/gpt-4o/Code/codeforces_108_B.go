package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() string {
	// Take input from the user
	var input string
	fmt.Scanln(&input)
	
	// Read the input, split it into a slice of integers, and store it in 'a'
	input = strings.TrimSpace(input)
	strs := strings.Split(input, " ")
	a := make([]int, len(strs))
	for i, str := range strs {
		num, _ := strconv.Atoi(str)
		a[i] = num
	}
	
	// Sort the slice 'a'
	sort.Ints(a)
	
	// Iterate through the sorted slice starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is not equal to the previous element
		// and if the current element is less than twice the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			return "YES"
		}
	}
	// If the loop completes without finding a match, return 'NO'
	return "NO"
}

func main() {
	// Print the result returned by the function 's()'
	fmt.Println(s())
}

// <END-OF-CODE>
