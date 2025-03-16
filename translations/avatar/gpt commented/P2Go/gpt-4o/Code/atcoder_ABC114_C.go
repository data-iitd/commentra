package main

import (
	"fmt"
	"strconv"
)

var N int

// Define a recursive function 'aaa' that takes a string 'n'
func aaa(n string) int {
	// Check if the integer value of 'n' exceeds the limit N
	num, _ := strconv.Atoi(n)
	if num > N {
		return 0 // If it does, return 0 (base case)
	}

	// Check if the digits of 'n' are exactly '7', '5', and '3'
	ans := 0
	if setEqual(n) {
		ans = 1
	}

	// Iterate over each character in the string '753'
	for _, i := range "753" {
		// Recursively call 'aaa' with the current number 'n' concatenated with 'i'
		ans += aaa(n + string(i))
	}

	// Return the accumulated answer
	return ans
}

// Helper function to check if the digits of 'n' are exactly '7', '5', and '3'
func setEqual(n string) bool {
	digits := map[rune]struct{}{}
	for _, ch := range n {
		digits[ch] = struct{}{}
	}
	_, has7 := digits['7']
	_, has5 := digits['5']
	_, has3 := digits['3']
	return has7 && has5 && has3 && len(digits) == 3
}

func main() {
	// Read an integer input from the user
	fmt.Scan(&N)

	// Print the result of calling 'aaa' with the initial value '0'
	fmt.Println(aaa("0"))
}

// <END-OF-CODE>
