package main

import (
	"fmt"
	"strconv"
)

func aaa(n string) int {
	// Check if the integer value of 'n' exceeds the limit N
	if int(n) > N {
		return 0 // If it does, return 0 (base case)
	}

	// Check if the digits of 'n' are exactly '7', '5', and '3'
	ans := 1
	if set(str(int(n))) == {'7', '5', '3'} {
		ans = 0
	}

	// Iterate over each character in the string '753'
	for _, i := range "753" {
		// Recursively call 'aaa' with the current number 'n' concatenated with 'i'
		ans += aaa(n + string(i))
	}

	// Return the accumulated answer
	return ans
}

func main() {
	// Read an integer input from the user
	fmt.Scan(&N)

	// Print the result of calling 'aaa' with the initial value '0'
	fmt.Println(aaa("0"))
}

func set(s string) map[string]bool {
	m := make(map[string]bool)
	for _, c := range s {
		m[string(c)] = true
	}
	return m
}

func str(i int) string {
	return strconv.Itoa(i)
}

