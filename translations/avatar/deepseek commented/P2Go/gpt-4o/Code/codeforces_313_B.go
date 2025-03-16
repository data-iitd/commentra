package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var soz string
	fmt.Scanln(&soz) // Take a string input from the user
	a := make([]int, len(soz)+1) // Initialize a slice 'a' with zeros, with a length of len(soz) + 1

	// Iterate over the string from index 1 to len(soz) - 1
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1] // Set 'a[i]' to the value of 'a[i - 1]'
		if soz[i-1] == soz[i] { // If the characters at positions 'i - 1' and 'i' are the same
			a[i]++ // Increment 'a[i]' by 1
		}
	}

	var n int
	fmt.Scanln(&n) // Take an integer input from the user
	arr := make([]int, 0) // Initialize an empty slice 'arr'

	// Iterate 'n' times
	for i := 0; i < n; i++ {
		var input string
		fmt.Scanln(&input) // Take input for 'm' and 'l'
		parts := strings.Split(input, " ")
		m, _ := strconv.Atoi(parts[0]) // Convert 'm' to integer
		l, _ := strconv.Atoi(parts[1]) // Convert 'l' to integer
		arr = append(arr, a[l-1]-a[m-1]) // Append the difference 'a[l-1] - a[m-1]' to 'arr'
	}

	// Print each element in 'arr'
	for _, value := range arr {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
