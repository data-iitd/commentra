package main

import (
	"fmt"
	"strings"
)

// Declare three string variables to store strings A, B, and C
var A, B, C string

func main() {
	// Initialize the string variables A, B, and C using fmt.Scanf function
	fmt.Scanf("%s %s %s", &A, &B, &C)

	// Calculate the length of strings A and B using len function and store the lengths in la and lb respectively
	la := len(A)
	lb := len(B)

	// Logical block to check if the last character of string A is same as the first character of string B
	// and the last character of string B is same as the first character of string C
	if A[la - 1] == B[0] && B[lb - 1] == C[0] {
		// If the condition is true, print YES on the console
		fmt.Println("YES")
	} else {
		// If the condition is false, print NO on the console
		fmt.Println("NO")
	}
}

