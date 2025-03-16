
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	var S string // String to store the input
	var score int // Variable to store the score

	// Read the input string
	S = readLine()

	// Iterate through each character in the string
	for i := 0; i < len(S); i++ {
		var my byte // Character representing my move
		var his byte // Character representing his move

		// Determine my move based on the index
		if i%2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}

		// Read his move from the input string
		his = S[i]

		// Update the score based on the moves
		if my != his {
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}

	// Print the score
	fmt.Println(score)
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	var S string
	var err error
	S, err = reader.ReadString('\n')
	if err != nil {
		if err == io.EOF {
			return ""
		}
		panic(err)
	}
	return strings.TrimSpace(S)
}

func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	var S string
	var err error
	S, err = reader.ReadString('\n')
	if err != nil {
		if err == io.EOF {
			return -1
		}
		panic(err)
	}
	return strconv.Atoi(strings.TrimSpace(S))
}

