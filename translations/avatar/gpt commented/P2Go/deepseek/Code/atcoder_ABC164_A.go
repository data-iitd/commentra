package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from input: S (the strength) and W (the weight)
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	S, _ := strconv.Atoi(parts[0])
	W, _ := strconv.Atoi(parts[1])
	
	// Check if the strength S is less than or equal to the weight W
	// If it is, print "unsafe"; otherwise, print "safe"
	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}
