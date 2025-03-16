package main

import (
	"fmt"
	"os"
)

func solve(S string, T string, A int, B int, U string) {
	if S == U {
		A--
	}
	if T == U {
		B--
	}
	fmt.Println(A, B)
}

func main() {
	var S, T, U string
	var A, B int

	// Reading input from standard input
	_, err := fmt.Scan(&S, &T, &A, &B, &U)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		return
	}

	solve(S, T, A, B, U)
}

// <END-OF-CODE>
