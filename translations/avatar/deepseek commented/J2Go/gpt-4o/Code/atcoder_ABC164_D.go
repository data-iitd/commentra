package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S)
	N := len(S)

	// Array to store remainders at each position
	modArr := make([]int, N)
	// Array to count occurrences of each remainder
	modCnt := make([]int, 2019)
	// Radix initialized to 1 for the least significant digit
	radix := 1

	// Process each character in the string from right to left
	for i := 0; i < N; i++ {
		tmp := (int(S[N-1-i]) - int('0')) * radix % 2019
		if i != 0 {
			tmp = (tmp + modArr[i-1]) % 2019
		}
		modArr[i] = tmp
		modCnt[tmp]++
		radix = radix * 10 % 2019
	}

	// Calculate the number of valid pairs using combinatorics
	ans := int64(0)
	modCnt[0]++ // Ensure 0 is counted
	for i := 0; i < 2019; i++ {
		ans += int64(modCnt[i]) * int64(modCnt[i]-1) / 2
	}

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
