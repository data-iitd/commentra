package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S) // Reading the first line of input as a string
	N := len(S)  // Getting the length of the string

	modArr := make([]int, N)      // Creating a slice of size N to store intermediate results
	modCnt := make([]int, 2019)    // Creating a slice of size 2019 to count the frequency of each number
	radix := 1                      // Initializing the radix to 1

	for i := 0; i < N; i++ { // Iterating through each character in the string
		tmp := 0 // Initializing a temporary variable to store the intermediate result

		// Calculating the value of the current digit in the given base
		tmp = (int(S[N-1-i]) - int('0')) * radix % 2019

		// Updating the temporary variable with the carry from the previous digit
		if i != 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}

		// Storing the intermediate result in the slice
		modArr[i] = tmp

		// Updating the frequency count of the current number in the slice
		modCnt[tmp]++

		// Updating the radix for the next iteration
		radix = radix * 10 % 2019
	}

	ans := int64(0) // Initializing a long variable to store the final answer

	// Calculating the answer by summing up the terms of the formula
	for i := 0; i < 2019; i++ {
		ans += int64(modCnt[i]) * int64(modCnt[i]-1) / 2
	}

	fmt.Println(ans) // Printing the final answer
}

// <END-OF-CODE>
