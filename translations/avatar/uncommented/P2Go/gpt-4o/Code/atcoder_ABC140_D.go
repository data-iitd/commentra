package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

var MOD = int(1e9 + 7)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Function to read an integer from input
	gi := func() int {
		input, _ := reader.ReadString('\n')
		num, _ := strconv.Atoi(input[:len(input)-1]) // Convert string to int
		return num
	}

	// Function to read a string from input
	gw := func() string {
		input, _ := reader.ReadString('\n')
		return input[:len(input)-1] // Remove newline character
	}

	N := gi()
	K := gi()
	S := gw()

	segCnt := 0
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}

	curHappy := N - 1 - segCnt
	var ans int
	if 2*K >= segCnt {
		ans = N - 1
	} else {
		ans = curHappy + 2*K
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
