package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Get the input as a list of two integers, S and W, using the map function
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	S, _ := strconv.Atoi(parts[0])
	W, _ := strconv.Atoi(parts[1])

	// Check if the condition S <= W is true or false and print the corresponding message
	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}
