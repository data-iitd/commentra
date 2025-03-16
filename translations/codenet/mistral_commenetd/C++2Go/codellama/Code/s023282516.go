package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare a string variable called S and read a string from the standard input
	var S string
	fmt.Scan(&S)

	// Reverse the string S and also reverse each string in the divide array
	S = Reverse(S)
	divide := []string{"dream", "dreamer", "erase", "eraser"}
	for i := 0; i < len(divide); i++ {
		divide[i] = Reverse(divide[i])
	}

	// Initialize a boolean variable called can to true
	can := true

	// Iterate through each character in the string S
	for i := 0; i < len(S); {
		// Initialize a boolean variable called can2 to false
		can2 := false

		// Iterate through each string in the divide array
		for j := 0; j < len(divide); j++ {
			// Get the string d from the divide array
			d := divide[j]

			// Check if the substring of S starting from the current index i and having the same size as d is equal to d
			if S[i:i+len(d)] == d {
				// If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
				can2 = true
				i += len(d)
			}
		}

		// If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
		if !can2 {
			can = false
			break
		}
	}

	// Output "YES" if can is true, otherwise output "NO"
	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

