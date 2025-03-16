package main

import (
	"fmt"
	"strings"
)

var divide = []string{"dream", "dreamer", "erase", "eraser"}

func main() {
	var S string
	fmt.Scan(&S)

	// Reverse the string S
	S = reverse(S)
	for i := range divide {
		divide[i] = reverse(divide[i])
	}

	can := true
	i := 0
	for i < len(S) {
		can2 := false // Check if we can divide with any of the 4 strings
		for _, d := range divide {
			if strings.HasPrefix(S[i:], d) { // Check if we can divide with d
				can2 = true
				i += len(d) // Move i forward by the length of d
				break       // Break to avoid checking other strings after a successful match
			}
		}
		if !can2 { // If we couldn't divide
			can = false
			break
		}
	}

	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
