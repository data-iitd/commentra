package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input string 'soz' from the user
	var soz string
	fmt.Scanln(&soz)

	// Initialize an array 'a' of size 'len(soz)+1' with zeros
	a := make([]int, len(soz)+1)

	// Iterate through the string 'soz' starting from index 1
	for i := 1; i < len(soz); i++ {
		// Assign the value of the previous index to the current index
		a[i] = a[i-1]

		// If the current character is same as the previous character, increment the count
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}

	// Take the number of test cases 'n' as input
	var n int
	fmt.Scan(&n)

	// Initialize an empty slice 'arr' to store the differences
	arr := make([]int, n)

	// Iterate through the test cases
	for i := 0; i < n; i++ {
		// Take two integers 'm' and 'l' as input, separated by a space
		var input string
		fmt.Scan(&input)
		parts := strings.Split(input, " ")
		m, _ := strconv.Atoi(parts[0])
		l, _ := strconv.Atoi(parts[1])

		// Calculate the difference between the count at index 'l' and index 'm'
		arr[i] = a[l-1] - a[m-1]
	}

	// Iterate through the slice 'arr' and print each difference
	for _, value := range arr {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
