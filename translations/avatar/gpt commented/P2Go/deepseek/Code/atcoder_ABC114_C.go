package main

import (
	"fmt"
	"strconv"
)

// Define a recursive function 'aaa' that takes an integer 'n'
func aaa(n int) int {
	// Check if the integer value of 'n' exceeds the limit N
	if n > N {
		return 0 // If it does, return 0 (base case)
	}

	// Check if the digits of 'n' are exactly '7', '5', and '3'
	ans := 1
	strN := strconv.Itoa(n)
	for _, digit := range strN {
		if digit != '7' && digit != '5' && digit != '3' {
			ans = 0
			break
		}
	}

	// Iterate over each character in the string '753'
	for _, char := range []string{"7", "5", "3"} {
		// Convert the character to an integer and recursively call 'aaa'
		num, _ := strconv.Atoi(char)
		ans += aaa(n*10 + num)
	}

	// Return the accumulated answer
	return ans
}

func main() {
	// Read an integer input from the user
	var N int
	fmt.Scan(&N)

	// Print the result of calling 'aaa' with the initial value 0
	fmt.Println(aaa(0))
}

