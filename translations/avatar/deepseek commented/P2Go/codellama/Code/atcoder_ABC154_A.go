
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(S, T string, A, B int, U string) {
	// Check if the string S is equal to the string U
	if S == U {
		// Decrement the count of A by 1
		A -= 1
	}
	// Check if the string T is equal to the string U
	if T == U {
		// Decrement the count of B by 1
		B -= 1
	}
	// Print the updated counts of A and B
	fmt.Println(A, B)
}

func main() {
	// Read the string S
	S := readString()
	// Read the string T
	T := readString()
	// Read the integer A
	A := readInt()
	// Read the integer B
	B := readInt()
	// Read the string U
	U := readString()
	// Call the solve function with the read inputs
	solve(S, T, A, B, U)
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	intValue, _ := strconv.Atoi(scanner.Text())
	return intValue
}

// 