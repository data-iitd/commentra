

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Declare three string variables A, B, and C to store the input strings
	var A, B, C string

	// Use the scanner to read three strings from the console and store them in variables A, B, and C
	scanner.Scan()
	A = scanner.Text()
	scanner.Scan()
	B = scanner.Text()
	scanner.Scan()
	C = scanner.Text()

	// Calculate the length of strings A and B using len function and store the lengths in la and lb respectively
	la := len(A)
	lb := len(B)

	// Logical block to check if the last character of string A is same as the first character of string B
	// and the last character of string B is same as the first character of string C
	if string(A[la-1]) == string(B[0]) && string(B[lb-1]) == string(C[0]) {
		// If the condition is true, print YES on the console
		fmt.Println("YES")
	} else {
		// If the condition is false, print NO on the console
		fmt.Println("NO")
	}
}

