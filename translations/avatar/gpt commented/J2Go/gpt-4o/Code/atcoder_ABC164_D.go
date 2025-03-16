package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the user
	var S string
	fmt.Scan(&S)

	// Get the length of the string S
	N := len(S)

	// Initialize an array to store the modulo results
	modArr := make([]int, N)

	// Initialize a count array for modulo values from 0 to 2018
	modCnt := make([]int, 2019)

	// Variable to keep track of the current radix (base 10 power)
	radix := 1

	// Loop through each character in the string S from the end to the beginning
	for i := 0; i < N; i++ {
		// Calculate the current digit's contribution to the modulo 2019
		tmp := (int(S[N-1-i]) - int('0')) * radix % 2019

		// If not the first character, add the previous modulo result
		if i != 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}

		// Store the current modulo result
		modArr[i] = tmp

		// Increment the count of this modulo result
		modCnt[tmp]++

		// Update the radix for the next digit (base 10)
		radix = radix * 10 % 2019
	}

	// Initialize the answer variable to count pairs
	var ans int64 = 0

	// Increment the count for modulo 0 to account for pairs starting from the beginning
	modCnt[0]++

	// Calculate the number of pairs of indices with the same modulo value
	for i := 0; i < 2019; i++ {
		ans += int64(modCnt[i] * (modCnt[i] - 1) / 2)
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
