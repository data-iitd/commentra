
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(S, T, U string, A, B int) {
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
	var err error

	// Read input from standard input.
	input := strings.Split(os.Args[1], " ")

	// Assign the first token to S.
	S = input[0]

	// Assign the second token to T.
	T = input[1]

	// Assign the third token to A.
	A, err = strconv.Atoi(input[2])
	if err != nil {
		fmt.Println(err)
		return
	}

	// Assign the fourth token to B.
	B, err = strconv.Atoi(input[3])
	if err != nil {
		fmt.Println(err)
		return
	}

	// Assign the fifth token to U.
	U = input[4]

	// Call the 'solve' function with the assigned variables.
	solve(S, T, U, A, B)
}

