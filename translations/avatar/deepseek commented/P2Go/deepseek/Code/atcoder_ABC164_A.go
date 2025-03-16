package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the values of S and W from a single line of input
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	S, _ := strconv.Atoi(parts[0])
	W, _ := strconv.Atoi(parts[1])
	// Check if the value of W is greater than or equal to S
	// If true, print "unsafe"
	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

